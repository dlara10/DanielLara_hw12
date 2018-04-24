import numpy as num
import matplotlib.pyplot as plt

d = num.loadtxt('advection.txt')
x=[1,2,3,4,5]




plt.plot(x, d, label='inicial')
plt.legend()
plt.xlabel("x")
plt.ylabel("f(x,t)")
plt.title('Adveccion lineal')
plt.savefig('adv_graph.png')
