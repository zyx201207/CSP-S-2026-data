#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
int x[100005];
void setup(){
	memset(x,0,sizeof(x));
}
bool check(int l,int r){
	queue<int> q;
	q.push(l);
	int cnt=0;
	bool flag=0;
	while(!q.empty()){
		int nn=q.size();
		for(int i=1;i<=nn;i++){
			int tp=q.front();
			q.pop();
			for(int v=tp+1;x[v]-x[tp]<=d&&v<=r;v++){
				if(v==r){
					flag=1;
					cnt++;
				}
				q.push(v);
			}
		}
		if(flag) return cnt==2?1:0;
	}
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		setup();
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int cnt=0;
		for(int i=1;i<=n-4+1;i++){
			for(int j=i+3;j<=n;j++){
				if(check(i,j)) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
