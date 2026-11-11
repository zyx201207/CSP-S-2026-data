#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=2000006;
int c,T,d;
int x[N];
int l[N],r[N];
vector<int> lv[N],rv[N];
int fl[N],fr[N];
int ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			lv[i].clear(); rv[i].clear();
		}
		int t=1;
		for(int i=1;i<=n;i++){
			while(t+1<=n&&x[t+1]-x[i]<=d) t++;
			if(t>i) r[i]=t,rv[t].push_back(i);
			else r[i]=0;
		}
		t=n;
		for(int i=n;i>=1;i--){
			while(t-1>=1&&x[i]-x[t-1]<=d) t--;
			if(t<i) l[i]=t,lv[t].push_back(i);
			else l[i]=0;
		}
		for(int i=1;i<=n;i++){
			fl[i]=(r[l[i]]==i?fl[l[i]]:0)+rv[i].size();
//			cout<<i<<":l-"<<l[i]<<",f:"<<fl[i]<<"\n";
		}
		for(int i=n;i>=1;i--){
			fr[i]=(l[r[i]]==i?fr[r[i]]:0)+lv[i].size();
//			cout<<i<<":r-"<<r[i]<<",f:"<<fr[i]<<"\n";
		}
		int j;
		ans=0;
		int rsz,lsz;
		for(int i=1;i<=n-1;i++){
			j=i+1;
			rsz=rv[j].size();
			if(r[i]==j) rsz--;
			lsz=lv[i].size();
			if(l[j]==i) lsz--;
//			cout<<i<<","<<j<<":\n";
//			cout<<"  sz:"<<lsz<<"*"<<rsz<<"\n";
//			if(lsz&&lv[i][0]==r[j]) cout<<"  r:"<<rsz<<"*"<<fr[r[j]]<<"\n";
//			if(rsz&&rv[j][0]==l[i]) cout<<"  l:"<<fl[l[i]]<<"*"<<lsz<<"\n";
			ans+=rsz*lsz;
			if(lsz&&lv[i][0]==r[j]) ans+=rsz*fr[r[j]];
			if(rsz&&rv[j][0]==l[i]) ans+=fl[l[i]]*lsz;
			if(rsz&&lv[i][0]==r[j]&&lsz&&rv[j][0]==l[i]) ans+=fl[l[i]]*fr[r[j]];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1 1
8 3
0 1 2 4 8 10 11 13
ans: 2
*/
