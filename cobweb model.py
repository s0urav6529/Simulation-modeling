import numpy as np
import matplotlib.pyplot as plt

a=12.4
b=1.2
c=8
d=0.6
pin=1

p=(a-c)/(b+d)

q=a-(b*p)

xaxis=list()
yaxis=list()

for i in range (12):
 s=c+(d*pin)
 pcur= abs(a-s)/b
 xaxis.append(pcur)
 yaxis.append(s)
 pin=pcur

plt.scatter(xaxis,yaxis)
plt.plot(p,q,marker="s",markersize=5,color="red")

