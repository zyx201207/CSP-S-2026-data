#include<bits/stdc++.h>
using namespace std;
long long n,m,o;
long long t,a[2000005],u1,u2,b[2000005];
void dfs(long long x,long long y,long long q,long long l){
	if(q==y){
		if(u2==0){
			u2=l;
		}
		if(u2==l){
			u1++;
		}
		else{
			u2=min(u2,l);
		}
		return;
	}
	if(q>y){
		return;
	}
	for(int i=m;i>=1;i--){
		if(b[q+i]) dfs(x,y,q+i,l+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int qwe;
	cin>>qwe>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1)o=a[i];
			a[i]=a[i]-o+1;
			b[a[i]]=1;
		}
		int g=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				u1=0;
				u2=0;
				dfs(a[i],a[j],a[i],0);
				if(u1==2)g++;
			}
		}
		cout<<g<<"\n";
	}
	return 0;
}