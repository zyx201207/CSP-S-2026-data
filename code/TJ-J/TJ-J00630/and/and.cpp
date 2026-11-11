#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],aa[200005],x=0;
long long s(int m1,int j){
	long long x1=0;
	if(m1+1==m){
		for(int i=j+1;i<=n;i++)	{
			long long aaa=a[i];
			for(int j=1;j<=m1;j++){
				aaa=aaa&aa[j];
			}
			x1=max(aaa,x1);
		}
		return x1;
	}
	for(int i=j+1;i<=n-m+1+m1;i++){
		aa[m1+1]=a[i];
		x1=max(x,s(m1+1,i));
	}
	return x1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xx=max(xx,a[i]);
	}
	if(m==1){
		cout<<xx;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		aa[1]=a[i];
		x=max(s(1,i),x);
	}
	cout<<x;
	return 0;
} 
