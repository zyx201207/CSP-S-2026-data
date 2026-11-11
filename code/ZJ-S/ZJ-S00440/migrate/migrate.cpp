#include<bits/stdc++.h>
using namespace std;
const int N=2e6 +5;
long long c,t,n,d,x[N],mi[N],an;
map<long long,int> e;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		sort(x+1,x+1+n);
		for(int i=1;i<=n;i++){
			for(int j=i+1;x[j]<=x[i]+d&&j<=n;j++){
				if(mi[j]==0) mi[j]=mi[i]+1;
				if(mi[j]!=mi[i]+1) continue;
				e[x[j]]++;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(e[x[j]]-e[x[i]]==2) an++;
			}
		}
		for(int i=1;i<=n;i++) e[x[i]]=mi[i]=x[i]=0;
		cout<<an<<'\n';
	}
	
	return 0;
}
