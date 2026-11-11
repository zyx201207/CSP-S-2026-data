//zhouyuanjie 陕西延安中学 SN-J00734 
#include<bits/stdc++.h>
using namespace std;

int er(int a){
	int b = 1, c = 0;
	while(b <= a){
		b *= 2;
		++c;
	}
	int num[c + 5];
	b /= 2;
	for(int i = 0; i < c; ++i){
		if(a >= b){
			num[i] = 1;
			a -= b;
			b /= 2;
		}
		else{
			num[i] = 0;
			b /= 2;
		}
	}
	int d = c, e = 1, f;
	for(int i = 1; i < c; ++i){
		e *= 10;
	}
	for(int i = 0; i < d; ++i){
		f += num[i] * e;
		e /= 10;
	}
	return f;
}

int main(){
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
	long long n, m, a, num[200009];
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> a;
		a = er(a);
		num[i] = a;
	}
	return 0;
}

