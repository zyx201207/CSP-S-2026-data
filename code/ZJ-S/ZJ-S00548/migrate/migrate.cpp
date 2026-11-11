#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,x[2000005],dd[5005],pt[5005],cnt;
vector<int> mp[5005];
queue<int> q;
bool vv[5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=2){
			cout<<0<<'\n';
			continue;
		}
	    if(11<=c&&c<=12){
	    	int dd=x[2]-x[1];
	    	d=d/dd;
	    	if(d<2){
	    		cout<<0<<'\n';
	    		continue;
			}
			else{
				int pp=2*d-1;
				cout<<std::max(n-pp,0ll)<<'\n';
				continue;
			}
		}
		if(c<=10){
			cnt=0;
			for(int i=1;i<=n;i++)mp[i].clear();
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					if(x[i]-x[j]<=d){
						mp[j].push_back(i);
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++)dd[j]=2e9,pt[j]=vv[j]=0;
				dd[i]=0;
				q.push(i);
				vv[i]=1;
				pt[i]=1;
				while(!q.empty()){
					int id=q.front();
					q.pop();
					for(int i=0;i<mp[id].size();i++){
						int v=mp[id][i];
						if(dd[id]+1<=dd[v])pt[v]+=pt[id];
						//cout<<id<<" "<<v<<" "<<dd[id]<<" "<<dd[v]<<'\n';
						dd[v]=std::min(dd[v],dd[id]+1);
						if(vv[v]==0)q.push(v);
						vv[v]=1;
					}
				}
				for(int j=i+1;j<=n;j++){
					//cout<<i<<" "<<j<<" "<<pt[j]<<'\n';
					if(pt[j]==2)cnt++;
				}
			}
			cout<<cnt<<'\n';
		}
	}
	return 0;
}
