#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ma;
long long a[200005];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		a[i]=x;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		k=a[1];
		for(int i=2;i<=n;i++){
			k&a[i];
		}
		cout<<k;
		return 0;
	}
	k=a[1];
	for(int j=2;j<=m;j++){
		k&=a[j];
	}
	for(int i=1;i<=n;i++){
		ma=a[i];
		for(int j=1+i;j<=i+m-1;j++){
			ma&=a[j];
		}
		if(k<ma){
			k=ma;
		}
	}
	cout<<k;
	return 0;
}
