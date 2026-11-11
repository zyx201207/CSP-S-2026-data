#include<bits/stdc++.h> 
using namespace std;
long long m,a[500001],n;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	bool f=1;
	for(int i=1;i<=n;i++)
		if(d[i+1]-d[i]!=d[i+2]-d[i-1])
			f=0;
	if(f){
		int base=d[2]-d[1],ans=0;
		for(int i=1;i<n;i++){
			ans+=base;
			if(ans>m){
				cout<<ans/base-1;
				return 0;
			}
		}
		cout<<n;
	}
	else{
		long long L1=0,R1=n+1;
		while(L1+1<R1){
			long long M=(L1+R1)/2;
			long long res=0;
			for(int i=1;i<M;i++)
				res+=M-a[i];
			if(res<=m)
				L1=M;
			else 
				R1=M;
		}
		long long L2=0,R2=n+1;
		while(L2+1<R2){
			long long M=(L2+R2)/2;
			long long res=0;
			for(int i=M+1;i<=n;i++)
				res+=a[i]-M;
			if(res>m)
				L2=M;
			else 
				R2=M;
		}
		cout<<max(L1,n-L2);
	}
}
