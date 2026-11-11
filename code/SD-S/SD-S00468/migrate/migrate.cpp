#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5,B=5005;
ll inf=1e18;
int n;
ll d,a[N];
int dis[B][B];
int cnt[B][B];
void brute_force(){
	for(int i=1;i<=n;i++)	for(int j=1;j<=n;j++)	cnt[i][j]=0;
	int ans=0;
	for(int r=1;r<=n;r++){
		multiset<pair<int,int> >st;
		int pos=r;
		st.insert({0,r});
		dis[r][r]=0;
		cnt[r][r]=1;
		for(int l=r-1;l>=1;l--){
			while(a[pos]-a[l]>d){
				auto it=st.find({dis[pos][r],pos});
				st.erase(it);
				pos--;
			}
			if(st.empty())	break;
			int minn=(*st.begin()).first;
			dis[l][r]=minn+1;
			for(pair<int,int>i:st){
				if(i.first==minn){
					cnt[l][r]+=cnt[i.second][r];
				}
				else	break;
				if(cnt[l][r]>=3)	break;
			}
			if(cnt[l][r]==2)	ans++;
			st.insert({dis[l][r],l});
		}
	}
	cout<<ans<<"\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<cnt[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>a[i];
		brute_force();
//		else if(c==11||c==12)	special_A(); 
	}
	return 0;
}
