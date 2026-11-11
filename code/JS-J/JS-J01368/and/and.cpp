#include<bits/stdc++.h>
using namespace std;
int n,m;
long long c;
int a[200005];
int b[20005];
bool v[200005][30];
bool xx[30];
long long sum,as;
int jj;
void f(long long x,int y){
	jj=31;
	for(long long i=1073741824;i>=1;i/=2){
		if(x>=i){
			x-=i;
			v[y][jj]=1;
		}
		jj--;
	}
	return;
}
void t(int ss,int zz){
	for(long long i=ss;i>=1;i--){
		sum=0;
		for(int j=1;j<=zz;j++){
			if(v[a[j]][i]==1){
				sum++;
				b[sum]=j;
			}
		}
		for(int i=1;i<=sum;i++){
			a[i]=b[i];
		}
		if(sum>=m){
			as=i;
			break;
		}
	}
	xx[as]=1;
	if(as==1){
		return;
	}
	t(as,sum);
	return;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		f(c,i);
	}
	t(23,n);
	for(int i=1;i<=20;i++){
		cout<<xx[i];
	}
	long long w=0;
	long long e=1;
	for(int i=1;i<=10;i++){
		if(xx[i]==1){
			w+=e;
		}
		e*=2;
	}
	cout<<w;
	return 0;
}
