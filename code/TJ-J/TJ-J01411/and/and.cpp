#include<bits/stdc++.h>

using namespace std;

int a[2000005];
int a1[2000005];

int suan(int b){
	int c = 0;
	while(b != 0){
		if(b & 1){
			c++;
		}
		b >>= 1;
	}
	return c;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max_ = 0,xia,max__ = 0,xia1,min_ = 1000000000,xia2;
	long long s;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		a1[i] = suan(a[i]);
		if(a1[i] > max_){
			max_ = a1[i];
			xia = i;
		}
		if(a[i] < min_){
			min_ = a[i];
			xia2 = i;
		}
	}
	if(m == 1){
		cout<<a[xia];
		return 0;
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			if(a1[i] > max__ && i != xia){
				max__ = a1[i];
				xia1 = i;
			}
		}
		cout<<(a[xia] & a[xia1]);
		return 0;
	}
	s = a[1];
	if(m == n){
		for(int i = 1;i <= n;i++){
			s = (s & a[i]);
		}
		cout<<s;
		return 0;
	}
	if(m == n - 1){
		for(int i = 1;i <= n;i++){
			if(i == xia2){
				continue;
			}
			s = (s & a[i]);
		}
		cout<<s;
		return 0;
	}
	cout<<a[1];
	return 0;
}
