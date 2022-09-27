import numpy as np
import matplotlib.pyplot as plt
import math
import random

def fun(x):
  return x*2

n,a,b,c =200,10,60,150
count = 0
xaxis = list()
yaxis = list()
dic = dict()

for i in range (a,b+2): 
  dic[i]=0

for i in range(n+1):
  x=random.randint(a,b+1)
  y=random.randint(0,c+1)

  if y<=fun(x):
    count+=1
    dic[x]+=1
    xaxis.append(x)
    yaxis.append(y)

plt.scatter(xaxis,yaxis)
print(count)

for i in dic:
  print(i,":",dic[i])
  
  
  
  
