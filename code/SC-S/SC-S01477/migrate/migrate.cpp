#include<bits/stdc++.h>
#define int long long
#define ri register int
#define ls(x) x<<1
#define rs(x) x<<1|1
#define PINF 1e18
#define NINF 1e18
#define inf 2114514
#define mf 5011
#define sf 1011
#define mp make_pair
#define pii pair<int,int>
using namespace std;
//性质1:等价结构（滑动窗口吐之前判断）
//性质2:恶性等价结构（滑动窗口吐之前判断）
int n,m,num[inf];
vector<pii> rcdlim;
vector<tuple<int,int,bool>> rcdcon; //为0良性，为1恶性
void solve(){
	int ans=0;
	cin >> n >> m;
	for(ri i=1;i<=n;i++) cin >> num[i];
	rcdlim.clear();
	//统计断区间
	int tmp=1;
	for(ri i=1;i<=n;i++){
		if(i==n) rcdlim.push_back(mp(tmp,n));
		else{
			if(num[i+1]-num[i]<=m) continue;
			rcdlim.push_back(mp(tmp,i));
			tmp=i+1;
		}
	}
	//处理每一个断区间
	for(ri i=0;i<rcdlim.size();i++){
		int l=rcdlim[i].first,r=rcdlim[i].second;
		rcdcon.clear();
		if(r-l+1<4) continue;
		int tmp=l+1;
		for(ri j=l+2;j<r;j++){
			if(num[j]-num[tmp]>m && j-tmp>=3){
				cout << tmp << "," << j << endl;
				rcdcon.push_back(make_tuple(tmp,j-1,true));
			}else if(num[j]-num[tmp]>m && j-tmp==2){
				rcdcon.push_back(make_tuple(tmp,j-1,false));
			}
			while(num[j+1]-num[tmp]>m || num[j]-num[tmp-1]>m) tmp++;
		}
		for(ri j=0;j<rcdcon.size();j++){
			if(get<2>(rcdcon[j])==true) continue;
			int x=0,y=0;
			if(j==0) x=l;
			else{
				if(get<2>(rcdcon[j-1])==false) x=get<0>(rcdcon[j-1]);
				else x=get<1>(rcdcon[j+1])-1;
			}
			if(j==rcdcon.size()-1) y=r;
			else{
				if(get<2>(rcdcon[j+1])==true) y=get<1>(rcdcon[j+1]);
				else x=get<0>(rcdcon[j+1])+1;
			}
			ans+=(get<0>(rcdcon[j])-x)*(y-get<1>(rcdcon[j]));
		}
		cout << ans << endl;
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T; cin >> c >> T;
	while(T--) solve();
	return 0;
}