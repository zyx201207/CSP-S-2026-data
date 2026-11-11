#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const int N = 2e6+10;
const int MOD =998244353;
const ll INF = 0x3F3F3F3F3F3F3F3F;
/*====================*/
ll a[N],dist[N],rt[N];
/*====================*/
void Solve(void){
	int n;ll d;cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;deque<int>q;
	for(int l=1;l<n;l++){
		dist[l]=0;rt[l]=1;
		q.clear();q.push_front(l);
		for(int i=l+1;i<=n;i++){
			while(!q.empty()&&a[i]-a[q.front()]>d)q.pop_front();
			if(q.empty())break;
			int fi=-1,se=-1,th=-1;
			fi=q.front();q.pop_front();
			if(!q.empty()){se=q.front();q.pop_front();}
			if(!q.empty()){th=q.front();q.pop_front();}
			if(th!=-1)q.push_front(th);
			if(se!=-1)q.push_front(se);
			q.push_front(fi);
			if(se==-1||dist[fi]!=dist[se]){
				rt[i]=rt[fi];
				dist[i]=dist[fi]+1;
			}else if(th==-1||dist[fi]!=dist[th]){
				rt[i]=rt[fi]+rt[se];
				dist[i]=dist[fi]+1;
			}else{
				rt[i]=rt[fi]+rt[se]+rt[th];
				dist[i]=dist[fi]+1;
			}
			while(!q.empty()&&dist[i]<dist[q.back()])q.pop_back();
			q.push_back(i);
			if(rt[i]==2)++ans;
			//cout<<dist[i]<<' '<<rt[i]<<'\n';
		}
		//cout<<'\n';
		//cout<<ans<<'\n';
	}cout<<ans<<'\n';
}
/*====================*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T=1;cin>>c>>T;
	while(T--)Solve();
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
//ªÿ¿¥∞…PCL T_T 
