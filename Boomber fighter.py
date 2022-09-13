import math
import random
import matplotlib.pyplot as plt

n=random.randint(1,10)

xb=[]
yb=[]

for i in range (n):
    x=random.randint(50,100)
    y=random.randint(50,100)
    xb.append(x)
    yb.append(y)

xf=[]
yf=[]

xx=random.randint(1,50)
yy=random.randint(1,50)

xf.append(xx)
yf.append(yy)

vf=random.randint(1,100)

i =0
while i<len(xb):
    dis = math.sqrt(math.pow(xb[i]-xf[i],2) + math.pow(yb[i]-yf[i],2))

    if dis >10:
        xx=xf[i] + (vf * (xb[i] - xf[i] ) / dis)
        yy=yf[i] + (vf * (yb[i] - yf[i] ) / dis)

        xf.append(xx)
        yf.append(yy)
    else :
        print(dis)
        break
    i+=1

    if i==len(xb) :
        print("Target Escaped")

plt.plot(xb,yb)
plt.plot(xf,yf)
plt.show()
