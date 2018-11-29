import numpy as numpy
def makeary():
	n = 10
	H = [[0 for i in range(n)] for j in range(n)]
	L = [[0 for i in range(n)] for j in range(n)]
	for i in range(n):
		L[i][i] = 1
		for j in range(n):
			H[i][j] = float(1/float(i+1+j+1-1))
	return H, L

def prtary(a):
	for i in range(len(a)):
		for j in range(len(a[i])):
			print("%0.7f" % (a[i][j]), end = ' ')
		print("\n")

def LUmul(L, U, x, y):
	m = U[y][y]/U[x][y]
	L[x][y] = m
	for i in range(len(U[x])):
		U[x][i] = U[y][i] - m*U[x][i]

	return L, U

def sub3_1():
	H,L = makeary()
	U = H

	for x in range(1, len(H)):
		for y in range(x):
			L, U = LUmul(L,U,x,y)

	return L

def sub3_2(L):
	b = []
	N = 10
	for i in range(N):
		b.append(i+1)
	ans = [b[0]/L[0][0]]
	
	temp = []
	for i in range(1,len(b)):
		for j in range(1,i+1):
			temp.append(L[i][j]*ans[j-1])
		for k in range(len(temp)):
			b[i] = b[i]-temp[k]
		ans.append(b[i]/L[i][0])
	print(ans)

def sub3_3(L):
	N = len(L)
	t = 0
	res = 1
	if len(L) == 2:
		return L[0][0]*L[1][1] - L[0][1]*L[1][0]
	for i in range(N-1):
		for j in range(i):
			for k in range(j, N):
				t = (L[i+1][j])/L[j][j]
				L[i+1][k] = L[i+1][k] - L[j][k]*t
			L[i+1][j] = 0
	for i in range(N):
		res = L[i][i]*res
	return res

def transposeM(H):
	return map(list, zip(*m))
def getMinor(H,i,j):
	return [row[:j] + row[j+1:] for row in (H[:i] + H[i+1:])]
def getdeter(H):
	if(len(H) == 2):
		return H[0][0]*H[1][1] - H[0][1]*H[1][0]
	deter = 0
	for i in range(len[H]):
		deter += ((-1)**i)*H[0][i]*getdeter(getMinor(H,0,i))
	return deter

def sub3_4(det):
	H, L = makeary()
	ans = []
	for i in range(len(H)):
		Hrow = []
		for j in range(len(H)):
			minor = getMinor(H,i,j)
			Hrow.append(((-1)**(i+j))*getdeter(minor))
		ans.append(Hrow)

	for i in range(len(ans)):
		for j in range(len(ans)):
			ans[i][j] = ans[i][j]/det
	prtary(ans)
print(sub3_3(sub3_1()))