import Mela
import numpy as np

associated_test = Mela.SimpleParticleCollection_t(
    [2, 1],
    [491.08166, 274.43945],
    [-0.714883,  1.2373503],
    [2.9122967, -2.589596],
    [0.0006989, 0.0005849],
    True #ptEtaPhiM vector
)

daughters_test = Mela.SimpleParticleCollection_t(
    [13, -13, 11, -11],
    [63.553325, 921.65033, 674.59143, 125.21847],
    [-1.177799, -1.180188, -0.235953, -0.099288],
    [0.6205077, 0.9990979, -1.406654, -1.148683],
    # [0, 0, 0, 0],
    [0.1056602, 0.1057852, 1.7767999, 1.7768000],
    True
)

mothers_test = Mela.SimpleParticleCollection_t(
    [1,2],
    [0,0],
    [0,0],
    [1067.5159, -2641.061],
    [1067.5159, 2641.0612],
    False
)

m = Mela.Mela()
# m.setVerbosity(Mela.VerbosityLevel.DEBUG_MECHECK)
probs = np.zeros((3,2), dtype=float)

m.setInputEvent(
    daughters_test,
    associated_test,
    mothers_test
)

for i, proc in enumerate([Mela.Process.HSMHiggs, Mela.Process.bkgZZ, Mela.Process.bkgZZ_SMHiggs]):
    m.setProcess(
        proc,
        Mela.MatrixElement.MCFM,
        Mela.Production.JJEW,
    )
    m.ghz1 = [1,0]
    m.ghw1 = [1,0]
    m.resetWidth(2.5, 23)
    m.resetWidth(2.08, 24)
    m.resetWidth(0.0041, 25)
    probs[i][0] = m.computeProdDecP(False)

    m.setProcess(
        proc,
        Mela.MatrixElement.MADGRAPH,
        Mela.Production.JJEW,
    )
    m.resetWidth(2.5, 23)
    m.resetWidth(2.08, 24)
    m.resetWidth(0.0041, 25)
    probs[i][1] = m.computeP(False)
    

print("raw probabilities (MCFM, MAD):")
print(probs)
print()

print("ratios:")
print(probs[:,0]/probs[:,1])
print()

print("ratios to BKG")
print(probs/probs[1])
print()


# print("ratios to SIG")
# print(probs/probs[0])
# print()

print("Interference value")
print(probs[2] - probs[1] - probs[0])


# m.setProcess(
#     Mela.Process.bkgZZ,
#     Mela.MatrixElement.MADGRAPH,
#     Mela.Production.JJEW,
# )
# print(m.computeP(False))
# m.mdl_cHWBtil = 1
# print(m.computeP(False))

