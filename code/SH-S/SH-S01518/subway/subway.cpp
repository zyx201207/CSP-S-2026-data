#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct lincon{
	int who,time;
};
int c,n,m,d,q;
ll ans=1<<62;
vector <int>fa[20004];
vector <int>toline[20004];
vector <lincon>linetr[505];
int x[2003],y[2003];
int exitt[200004];
bool flag[505];
ll goc(int g,int h){
	if(g==h)return 0;
	if(flag[g])return 1<<62;
	    flag[g]=1;
	    ll tem=1<<62;
		for(int i=0;i<linetr[g].size();i++){
			    //cout<<"linetr[g][i].time"<<linetr[g][i].time<<endl;
				tem=min(tem,linetr[g][i].time
				+goc(linetr[g][i].who,h));
				//cout<<"g="<<g<<" h="<<h<<"    tem"<<tem<<endl;
		}
		flag[g]=0;
		return tem;
}
ll solve(int a,int b){
	if(a==b)return 0;
	
	for(int i=0;i<fa[a].size();i++)
		for(int j=0;j<fa[b].size();j++){
			ans=min(ans,toline[a][fa[a][i]]+toline[b][fa[b][j]]
			+goc(fa[a][i],fa[b][j]));
		}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>exitt[i];
	for(int i=1;i<=n;i++){
		int a,t,k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			fa[a].push_back(i);
			toline[a].push_back(t);
			if(fa[a].size()>1)
				for(int p=0;p<fa[a].size()-1;p++){
					lincon l;
					l.who=fa[a][p];
					l.time=toline[a][p]+toline[a][fa[a].size()-1];
					
					//cout<<l.time<<endl;
					linetr[i].push_back(l);
					l.who=i;
					linetr[fa[a][p]].push_back(l);
					//cout<<"time "<<i<<" "<<fa[a][p]<<"  "<<l.time<<endl;
					//cout<<"time "<<fa[a][p]<<" "<<i<<"  "<<endl;
				}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		cout<<exitt[x[i]]+exitt[y[i]]+solve(x[i],y[i])<<endl;
		ans=1<<62;
	}
	
	return 0;
}
