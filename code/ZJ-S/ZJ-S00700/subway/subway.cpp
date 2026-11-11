#include<bits/stdc++.h>//Oct31==Dec25?
using namespace std;
typedef long long ll;
ll a[500005],n,m,d,q;
struct qw{
	ll t;
	ll x;
};
vector<qw>tme[50005];
vector<int>xian[50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int meiyong;
	cin>>meiyong>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int xx;
		cin>>xx;
		int zhandian,shijian;
		if(xx==1){
			cin>>zhandian>>shijian;
			continue;
		}
		while(xx--){
			cin>>zhandian>>shijian;
			tme[zhandian].push_back((qw){shijian,i});
			xian[i].push_back(zhandian);
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		if(l>r){
			swap(l,r); 
		}
		int min=1e9;
		ll ans=a[l]+a[r];
		for(int i=1;i<tme[l].size();i++){
			if(tme[l][i].t<min){
				min=tme[l][i].t;
			}
		}
		int now=l;
		while(now!=r){
			cout<<now;
			for(int i=0;i<tme[now].size();i++){
				if(xian[tme[now][i].x][0]==now){
					ans+=tme[xian[tme[now][i].x][1]][i].t;
					now=xian[tme[now][i].x][1];
				}else{
					ans+=tme[xian[tme[now][i].x][0]][i].t;
					now=xian[tme[now][i].x][0];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
