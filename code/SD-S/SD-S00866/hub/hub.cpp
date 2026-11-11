#include <bits/stdc++.h>
using namespace std;
const int M=400;
long long c,t,n,k,q[M+5],dis[M+5];
bool vis[M+5],ifm[M+5];
vector<long long>g[M+5],v;
void ifdfs(long long x){//cout<<x<<" ";
	vis[x]=true;
	for (int i=0;i<g[x].size();i++){
		long long ch=g[x][i];//cout<<ch<<<<endl;
		if ((!vis[ch])&&ifm[ch]){
			ifdfs(ch);
		}
	}
}
long long ans=0;
void sos(long long x,long long j){
	if (x>=k){
		long long x=0;
		for (int i=0;i<v.size();i++){//cout<<v[i]<<" sdfa"<<endl;;
			if (!vis[v[i]]){
				ifdfs(v[i]);
				x++;
				if (x>2){//cout<<endl;
					for (int i=1;i<=n;i++){
						vis[i]=false;
					}
					return ;
				}
			}//cout<<endl;
		}//cout<<endl;
		for (int i=1;i<=n;i++){
			dis[i]=(1LL<<60);
		}
		long long head=1,tail=0;
		for (;tail<v.size();tail++){
			q[tail+1]=v[tail];
			dis[v[tail]]=0;
		}
		while (head<=tail){
			long long xx=q[head];//cout<<xx<<"  "<<dis[xx]<<endl;
			head++;
			for (int i=0;i<g[xx].size();i++){
				long long ch=g[xx][i];
				if (dis[xx]+1<dis[ch]){
					dis[ch]=dis[xx]+1;
					q[++tail]=ch;
				}
			}
		}
		long long mx=0;
		for (int i=1;i<=n;i++){
			vis[i]=false;
			mx=max(mx,dis[i]);
		}
		ans=min(ans,mx);
		return ;
	}
	for (int i=j+1;i<=n;i++){
		v.push_back(i);
		ifm[i]=true;
		sos(x+1,i);
		v.pop_back();
		ifm[i]=false;
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while (t--){
		ans=(1LL<<60);
		cin>>n>>k;
		for (int i=1;i<n;i++){
			long long u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		sos(0,0);
		cout<<ans<<endl;
		for (int i=1;i<=n;i++){
			g[i].clear();
		}//cout<<"gerbsehdfhdg";
	}
	return 0;
}

