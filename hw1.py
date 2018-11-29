from math import exp
from math import cos
from math import sin

n = 10
def exact(x):
	return exp(x)*cos(2*x)

def culhi(arrayx):
	hi = []
	for i in range(n):
		hi.append(arrayx[i+1]-arrayx[i])
	return hi

def cularpha(hi, arrayy):
	arpha = [0]
	for i in range(1,n):
		arpha.append(float(3.0/hi[i])*(arrayy[i+1]-arrayy[i])-float(3.0/hi[i-1])*(arrayy[i]-arrayy[i-1]))
	return arpha

def cubic():
	l = [1.0]
	u = [0.0]
	z = [0.0]
	b = []
	c = [0.0]*10
	d = []
	xpoints = [0.0,0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0]
	ypoints = [1.0,1.125,1.039,0.6663,-0.0650,-1.131,-2.448,-3.821,-4.944,-5.425,-4.83]

	hi = [0.2]*10
	arpha = cularpha(hi,ypoints)
	for i in range(1,n):
		l.append(2.0*(xpoints[i+1]-xpoints[i-1])-(hi[i-1]*u[i-1]))
		u.append(hi[i]/l[i])
		z.append((arpha[i]-(hi[i-1]*z[i-1]))/l[i])

	l.append(1.0)
	z.append(0.0)
	c.append(0.0)
	j = n-1
	while j>-1:
		c[j] = (z[j]-(u[j]*c[j+1]))
		b.append(((ypoints[j+1]-ypoints[j])/hi[j]) - (hi[j]*(c[j+1]+2.0*c[j])/3.0))
		d.append((c[j+1]-c[j])/(3.0*hi[j]))
		j = j-1
	return xpoints, ypoints, b, c, d

def rfun(a,b,c,d,x,xj):
	S = a + (b*(x-xj)) + (c*((x-xj)**2.0)) + (d*((x-xj)**3.0))
	dS = b + 2.0*c*(x-xj) + (3.0*d*((x-xj)**2.0))
	return S, dS

def main():
	xpoints, a, b, c, d = cubic()
	x = 0.5
	fir = 0
	while (xpoints[fir] <= 0.6):
		fir = fir+1
	cans, dcans = rfun(a[fir],b[fir],c[fir],d[fir],x,xpoints[fir])
	exactv = exp(x)*cos(2*x)
	deactv = exp(x)*cos(2*x) - 2*exp(x)*sin(2*x)
	print("x = 0.5")
	print("my function value : %f \n my derivative value : %f"%(cans, dcans))
	print("exact function value : %f \n exact derivative value : %f"%(exactv, deactv))
	print("function difference : %f derivative value difference : %f"%(abs(exactv-cans),abs(deactv-dcans)))
	print("\n")

	x = 1.5
	fir = 0
	while (xpoints[fir] <= 1.6):
		fir = fir+1
	cans, dcans = rfun(a[fir],b[fir],c[fir],d[fir],x,xpoints[fir])
	exactv = exp(x)*cos(2*x)
	deactv = exp(x)*cos(2*x) - 2*exp(x)*sin(2*x)
	print("x = 1.5")
	print("my function value : %f \n my derivative value : %f"%(cans, dcans))
	print("exact function value : %f \n exact derivative value : %f"%(exactv, deactv))
	print("function difference : %f derivative value difference : %f"%(abs(exactv-cans),abs(deactv-dcans)))
	
main()