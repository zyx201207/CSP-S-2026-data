#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int t,n,k,x,y,b[15],cnt,cn,mi=INT_MAX,ma,mm,dis[15][15];
vector<int> a[15];
bool is[15],ih[15];
void df(int d){
	for(int i=0;i<a[d].size();i++){
		if(!is[a[d][i]] && ih[a[d][i]]){
			is[a[d][i]]=1,df(a[d][i]);
		}
	}
}
void dg(int d){
	if(d==n+1){
		memset(is,0,sizeof is);
		memset(ih,0,sizeof ih);
		cn=0;
		for(int i=1;i<=cnt;i++){
			ih[b[i]]=1;
		}
		for(int i=1;i<=cnt;i++){
			if(!is[b[i]]){
				cn++;
				df(b[i]);
			}
		}
		if(cn==2){
			ma=0;
			for(int i=1;i<=n;i++){
				mm=INT_MAX;
				for(int j=1;j<=cnt;j++){
					mm=min(mm,dis[i][b[j]]);
				}
				ma=max(ma,mm);
			}
			mi=min(mi,ma);
		}
		return;
	}
	dg(d+1);
	if(cnt<k){
		b[++cnt]=d;
		dg(d+1);
		cnt--;
	}
}
void df2(int d,int ro){
	for(int i=0;i<a[d].size();i++){
		if(dis[a[d][i]][ro]==-1){
			dis[a[d][i]][ro]=dis[d][ro]+1,df2(a[d][i],ro);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>k;
		mi=INT_MAX;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			a[x].push_back(y),a[y].push_back(x);
		}
		memset(dis,-1,sizeof dis);
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			df2(i,i);
		}
		dg(1);
		cout<<mi<<endl;
	}
	return 0;
}
