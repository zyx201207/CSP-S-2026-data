#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll rd(){
	char ch=getchar();bool f=0;ll ret=0;
	while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
	while(ch<='9'&&ch>='0') ret*=10,ret+=ch-'0',ch=getchar();
	return f?-ret:ret;
}
ll F[505][505];
ll t2[500005];
vector<pair<ll,ll> > S[505];
vector<int> pos[500005];
int find(int i,ll x){
	int l=0,r=S[i].size()-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(S[i][mid].first<x) l=mid+1;
		else if(S[i][mid].first>x) r=mid-1;
		else return mid;
	} 
	return l;
} 
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
	return a.first<b.first;
}
inline ll mn(ll x,ll y){return x<y?x:y;}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++) t2[i]=rd();
	for(int i=1;i<=n;i++){
		int k;k=rd();
		for(int j=1;j<=k;j++) {ll x=rd(),y=rd();S[i].push_back({x,y});pos[x].push_back(i);}
		sort(S[i].begin(),S[i].end(),cmp);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		//	if(!(i==1&&j==2)) continue;
			for(int x=0,y=0;x<S[i].size()&&y<S[j].size();){
			//	cout<<"T "<<i<<' '<<j<<endl;
				//cout<<i<<" "<<j<<" T "<<x<<' '<<y<<' '<<S[i][x].first<<' '<<S[j][y].first<<endl;
				if(S[i][x].first>S[j][y].first) ++y;
				else if(S[i][x].first<S[j][y].first) ++x;
				else{
					if(F[i][j]==0) F[i][j]=F[j][i]=S[i][x].second+S[j][y].second;
					else F[i][j]=min(F[i][j],S[i][x].second+S[j][y].second);
					++x,++y;
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(!F[i][k]) continue;
			for(int j=1;j<=n;j++){
				if(!F[j][k]) continue;
				if(i==j) continue;
				if(!F[i][j]) F[i][j]=F[i][k]+F[k][j];
				else  F[i][j]=min(F[i][k]+F[k][j],F[i][j]);
	
			}
		}
	}
	while(q--){
		ll x=rd(),y=rd();ll ans=1e18;
		for(int i=0;i<pos[x].size();++i){
			for(int j=0;j<pos[y].size();++j){
			//	cout<<i<<" "<<j<<endl;
				ll sum=F[pos[x][i]][pos[y][j]];
				sum+=S[pos[x][i]][find(pos[x][i],x)].second+S[pos[y][j]][find(pos[y][j],y)].second;
				ans=mn(ans,sum);
			}
		}
		cout<<t2[x]+t2[y]+ans<<endl;
	}
	return 0;
}
