#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500001
int n,m,c,d,q,x,u[N]={0},v_[N]={0},st[N]={0},e[N]={0},U,V;
bool check[N]={0};
int a[N]={0},ans[N]={0};
bool check=1;
vector<int> vu[N],vv[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	while(n--){
		cin>>x;
		for(int i=1;i<=x;i++){
			cin>>U>>V;
			u[i]=U;
		}
		for(int i=1;i<=x;i++)
			for(int j=i+1;j<=x;j++){
				vu[u[i]].push_back(u[j]);
				vv[u[i]].push_back(v_[i]+v_[j]);
				vu[u[j]].push_back(u[i]);
				vv[u[j]].push_back(v_[i]+v_[j]);
		}
	}
	int Q=q;
	while(q--){cin>>st[Q-q+1]>>e[Q-q+1];}
	q=Q;
	while(q--){
		int minn=0x7fffffff,t,cnt=0,z_;
		memset(ans,0x3f,sizeof(ans));
		memset(check,0,sizeof(check));
		ans[st[Q-q+1]]=0;
//		cout<<st<<' '<<e<<' ';
		while(cnt<m){
			minn=0x7ffffffff;
			for(int i=1;i<=m;i++){
				if(check[i]==0&&minn>ans[i])
					if(minn>ans[i]){
						minn=ans[i],t=i;
					}
			}
			check[t]=1;
			for(int i=0;i<vu[t].size();i++){
				z_=vu[t][i];
				ans[z_]=min(ans[z_],ans[t]+vv[t][i]);
			}
			cnt++;
//			cout<<t<<' ';
		}
		cout<<ans[e[Q-q+1]]+a[st[Q-q+1]]+a[e[Q-q+1]]<<'\n';
	}
	
	return 0;
	
} 

//
/*
 地铁口->站厅->站台->站厅2->站台2->...
 ->终点站厅->终点地铁口 
*/ 
