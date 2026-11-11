#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int Cnt(int a,int b){
	int t=0,r=1;
	while(a!=0&&b!=0){
		bool t1=a%2,t2=b%2;
		t+=(t1&&t2)*r;
		r*=2;
		a/=2;
		b/=2;
	}
	return t;
}
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(m==1)
			maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,Cnt(a[i],a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}
/*
4 2
3 15 12 12
*/
