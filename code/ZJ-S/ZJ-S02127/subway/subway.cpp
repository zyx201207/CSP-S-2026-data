#include<bits/stdc++.h>
using namespace std;
const int M=5e5+2,N=502,D=22;
int c,n,m,d,q,x,y,a,jj;
bool flag;
struct Station{
	int w,t[N];
	vector<int> rt;
}station[M];
struct Route{
	int k;
	vector<int> st;
}route[N];
long long time(int x,int y){
	long long ans=station[x].w+station[y].w;
	for(int i=0;i<station[x].rt.size();i++){
		flag=true,jj=0;
		for(int j=0;j<=route[station[x].rt[i]].st.size();j++){
			if(route[station[x].rt[i]].st[j]==x){
				flag=false;
				jj=j;
				break;
			}
		}
		for(int j=jj+1;j<=route[station[x].rt[i]].st.size();j++){
			if(route[station[x].rt[i]].st[j]==y){
				flag=true;
			}
			if(flag){
				ans+=station[x].t[station[x].rt[i]]+station[y].t[station[x].rt[i]];
				break;
			}
		}
	}
	if(ans!=station[x].w+station[y].w)return ans;
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>station[i].w;
	for(int i=1;i<=n;i++){
		cin>>route[i].k;
		for(int j=1;j<=route[i].k;j++){
			cin>>a;
			route[i].st.push_back(a);
			cin>>station[a].t[i];
			station[a].rt.push_back(i);
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<time(x,y)<<"\n";
	}
	return 0;
}
