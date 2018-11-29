from math import exp
from math import cos
from math import sin

arpha = 2
a = 0.0
b = 2.0


def fty(t, w):
	return t+w


def exact(x):
	return 3*exp(x) - x - 1.0

def main():
	h = 0.05
	t = arpha
	w = arpha
	wn = 0
	t0 = 0.0

	while(t <= b):
		t = t0 + h
		k1 = h*fty(t, w)
		k2 = h*fty(t + h/2, w + k1/2)
		k3 = h*fty(t + h/2, w + k2/2)
		k4 = h*fty(t, w + k3)
		wn = w + (k1 + 2*k2 + 2*k3 + k4) / 6

		t0 = t
		w = wn

	h005 = wn

	h = 0.1
	t = arpha
	w = arpha
	wn = 0
	t0 = 0.0

	while( t <= b):
		t = t0 + h
		k1 = h*fty(t, w)
		k2 = h*fty(t + h/2, w + k1/2)
		k3 = h*fty(t + h/2, w + k2/2)
		k4 = h*fty(t, w + k3)
		wn = w + (k1 + 2*k2 + 2*k3 + k4) / 6

		t0 = t
		w = wn
	h01 = wn

	h = 0.2
	t = arpha
	w = arpha
	wn = 0
	t0 = 0.0


	while( t <= b):
		t = t0 + h
		k1 = h*fty(t, w)
		k2 = h*fty(t + h/2, w + k1/2)
		k3 = h*fty(t + h/2, w + k2/2)
		k4 = h*fty(t, w + k3)
		wn = w + (k1 + 2*k2 + 2*k3 + k4) / 6

		t0 = t
		w = wn
	h02 = wn

	print("h = 0.05 : %f, h = 0.1 : %f, h = 0.2 : %f, \
		exact value = %f" %(h005, h01, h02, exact(2)))

main()