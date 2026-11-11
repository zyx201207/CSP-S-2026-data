#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll d,x[2000005];
int nex[2000005],pre[2000005];
int cnex[2000005],cpre[2000005];
int L1[2000005],R1[2000005];
int L2[2000005],R2[2000005];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i],L1[i]=L2[i]=1,R1[i]=R2[i]=0;
	for(int i=1,j=1;i<=n;i++){
		while(x[i]-x[j]>d) j++;
		pre[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(x[j]-x[i]>d) j--;
		nex[i]=j;
	}
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&nex[j+1]==nex[j]) j++;
		L1[nex[j]]=i,R1[nex[j]]=j;
	}
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&pre[j+1]==pre[j]) j++;
		L2[pre[j]]=i,R2[pre[j]]=j;
	}
	for(int i=1;i<=n;i++) R1[i]=min(R1[i],i-1),L2[i]=max(L2[i],i+1);
	for(int i=1;i<=n;i++){
		if(pre[i]==i) cpre[i]=1;
		else if(nex[pre[i]]==i) cpre[i]=cpre[pre[i]]+(R1[i]-L1[i])+1;
		else cpre[i]=max(0,R1[i]-L1[i]+1)+1;
	}
	for(int i=n;i>=1;i--){
		if(nex[i]==i) cnex[i]=1;
		else if(pre[nex[i]]==i) cnex[i]=cnex[nex[i]]+(R2[i]-L2[i])+1;
		else cnex[i]=max(0,R2[i]-L2[i]+1)+1;
	}
	ll res=0;
	for(int i=1;i<=n;i++) R1[i]=min(R1[i],i-2),L2[i]=max(L2[i],i+2);
	for(int i=1;i<n;i++) if(L1[i+1]<=R1[i+1]&&L2[i]<=R2[i]){
		int ls=R1[i+1]-L1[i+1]+1+(pre[i]==L1[i+1])*(cpre[pre[i]]-1);
		int rs=R2[i]-L2[i]+1+(nex[i+1]==R2[i])*(cnex[nex[i]]-1);
		res+=1ll*ls*rs;
	}
	cout<<res<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int ID,Ca;cin>>ID>>Ca;while(Ca--)solve();
	return 0;
}