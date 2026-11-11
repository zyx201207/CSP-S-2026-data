#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>dr;
ll c,n,m,d,q;
ll w[1000+10],a[1000+10][1000+10],t[1000+10][1000+10];
vector<ll>dt[1000+10][5];
ll qu[1000000+10][2+5],bj[1000+10];
void add(ll x,ll y,ll t){
	dt[x][1].push_back(y);
	dt[x][2].push_back(t);
}
void bfs(int l,int r){
	qu[1][1]=l;
	qu[1][2]=w[l];
	ll sj=0;
	ll head=1,end=1;
	while(head<=end){
		int sz=qu[head][1];
		bj[qu[head][1]]=1;
		if(qu[head][1]==r){
			cout<<qu[head][2]<<endl;
				return;
			}
		for(ll i=0;i<=dt[sz][1].size();i++){
			if(bj[dt[sz][1][i]]==0){
				end++;
				qu[end][1]=dt[sz][1][i];
				qu[end][2]=qu[head][2]+w[end]+dt[sz][2][i]+dt[qu[end][1]][2][i];
			}
		}
		head++;
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	bool o=1;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		if(k>2)o=0;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			if(j!=1){
				add(a[i][j],a[i][j-1],t[i][j]);
				add(a[i][j-1],a[i][j],t[i][j-1]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(o==1){
			bfs(x,y);
		}
	}
	
	} 
	
	return 0;
}