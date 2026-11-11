#include<iostream>
#include<cstdio>
#include<vector>
#define endl '\n'
#define ll long long
#define eb emplace_back
using namespace std;

const int MAXN=2e6+10;

int n,ne[MAXN],la[MAXN],numl[MAXN],numr[MAXN],lp[MAXN],rp[MAXN];
ll ans,d,x[MAXN];
vector<int> sl[MAXN],sr[MAXN];

void mian(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i],numl[i]=numr[i]=0,lp[i]=n+1,rp[i]=0,vector<int>().swap(sl[i]),vector<int>().swap(sr[i]);
	for(int i=1,r=1;i<=n;i++){
		while(r<n&&x[r+1]-x[i]<=d) r++;
		ne[i]=r;
	}
	for(int i=n,l=n;i;i--){
		while(l>1&&x[i]-x[l-1]<=d) l--;
		la[i]=l;
	}
	for(int i=1;i<=n;i++) sr[la[i]].eb(i),sl[ne[i]].eb(i);
	for(int i=1;i<=n;i++) lp[la[i]]=min(lp[la[i]],i),rp[la[i]]=max(rp[la[i]],i);
	for(int i=1;i<=n;i++){
		numl[i]=1;
		if(ne[la[i]]==i) numl[i]+=numl[la[i]];
		for(int j:sl[i]) if(ne[j]==i&&j>la[i]&&j!=i) numl[i]++; 
	}
	for(int i=n;i;i--){
		numr[i]=1;
		if(la[ne[i]]==i) numr[i]+=numr[ne[i]];
		for(int j:sr[i]) if(la[j]==i&&j<ne[i]&&j!=i) numr[i]++;
	}
	for(int i=1;i<=n;i++){
		int p=ne[i];
		if(p==i+1) continue;
		int l=lp[p-1],r=rp[p-1],j=ne[p];
		if(j==p) continue;
		if(la[j]==p-1){
			if(la[p-1]==i){
				ans+=1ll*numl[i]*numr[j];
				j--;
			}else{
				ans+=numr[j],j--;
			}
		}
		r=min(r,j);
		ans+=1ll*max(0,r-l+1)*(la[p-1]==i?numl[i]:1);
	}
	cout<<ans<<endl;
	return;
}

int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;cin>>t>>t;while(t--) mian();
	return 0;
}
