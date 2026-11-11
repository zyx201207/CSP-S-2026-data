#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int d[100010][100010];
pair<int,int> s[100010];
int f[100010];
int as[100010];
int fin(int x){
	if(x!=f[x]){
		f[x]=fin(f[x]);
	}
	return f[x];
}
bool sp(pair<int,int> a,pair<int,int> b){
	return a.first<b.first;
}
bool pp(int x,int id,vector<vector<int>> &g,vector<vector<int>> &v){
	for(const int c:v[id]){
		for(const int z:g[c]){
			if(z==s[x].second){
				return true;
			}
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(nullptr);
	cin.tie(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int C,T,n,k;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		vector<vector<int>> g(n+1);
		vector<vector<int>> v(2);
		int a,b;
		for(int i=1;i<n;i++){
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for(int i=1;i<=n;i++){
			f[i]=i;
			memset(d,0x3f,sizeof(d));
			q.push({0,i});
			d[i][i]=0;
			while(!q.empty()){
				a=q.top().second;
				b=q.top().first;
				q.pop();
				if(b>d[i][a]){
					continue;
				}
				for(const int c:g[a]){
					if(b+1<d[i][c]){
						d[i][c]=b+1;
						q.push({d[i][c],c});
					}
				}
			}
			s[i]={0,i};
			for(int j=1;j<=n;j++){
				s[i].first=max(s[i].first,d[i][j]);
			}
		}
		sort(s+1,s+n+1,sp);
		int cnt=0,ans=0;
		memset(as,0x3f,sizeof(as));
		for(int i=1;i<=n;i++){
			if(cnt==0){
				cnt=1;
				v[0].push_back(s[i].second);
				k--;
				as[s[i].first]=0;
			}else if(cnt==1){
				if(pp(i,0,g,v)){
					v[0].push_back(s[i].second);
				}else{
					v[1].push_back(s[i].second);
					cnt=2;
				}
				k--;
				as[s[i].first]=0;
			}else{
				if(pp(i,0,g,v)){
					v[0].push_back(s[i].second);
					k--;
					as[s[i].first]=0;
				}else if(pp(i,1,g,v)){
					v[1].push_back(s[i].second);
					k--;
					as[s[i].first]=0;
				}
			}
			if(k==0){
				break;
			}
		}
		for(const int i:v[0]){
			for(int j=1;j<=n;j++){
				as[j]=min(as[j],d[i][j]);
			}
		}
		for(const int i:v[1]){
			for(int j=1;j<=n;j++){
				as[j]=min(as[j],d[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			ans=max(as[i],ans);
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
