#include<bits/stdc++.h>
using namespace std;
int s[300000];
int re(int a){
	int re[300000];
	int r = a,x=0,cnt=0,f=1;
	while(r!=1){
		re[cnt++] = r%2;
		r /= 2;
	}
	re[cnt]=1;
	for(int i = 0;i<=cnt;i++){
		x+=re[i]*f;
		f*=10;
	}
	return x;
}
int an(int a,int b){
	int aa=a,bb=b,f=0,ad=0,f1=1;
	int c=min(a,b);
	while(c/=10){
		f++;
		if(aa%10==1&&bb%10==1){
			for(int i = 1;i<=f-1;i++){
				f1*=2;
			}
			ad+=f1;
		}
	}
	ad++;
	return ad;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ad=0;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> s[i];
	}
	for(int i = 1;i<=n;i++){
		s[i]=re(s[i]);
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(ad<an(s[i],s[j])){
				ad=an(s[i],s[j]);
			}
		}
	}
	cout << ad;
	return 0;
}