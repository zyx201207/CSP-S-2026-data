#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct ke{
	int a,t;
};
int del=0;
stack<int> rp;
bool nu(int x,int y,vector<int> ki,vector<ke> k[]){
	if(x!=y&&del!=0) return 0;
	int r,ans=0;
	int i;
	for(int j=0;j<ki[x];j++){
		i=j;
		rp.push(k[x][i].a);
		bool b=nu(k[x][i].a,y,ki,k);
		if(!b) rp.pop();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m,0);
	int x,y,ki;
	for(int i=0;i<m;i++) cin>>w[i];
	vector<ke> k[n];
	vector<int> ki(n,0);
	for(int i=0;i<n;i++){
		cin>>ki[i];
		for(int j=0;j<ki;j++){
			cin>>x>>y;
			k[i][j].a=x;
			k[i][j].t=y;
		}
	}
	lo=0;
	for(int i=1;i<n;){
		nu(x,y,ki,k);
		for(int j=0;j<ki[rp[lo]];j++){
			if(k[i][j].a==rp[lo]){
				ans+=k[i][j].t;
			}
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
		
