#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],p[100005],ans[100005],l[100005],q[100005];
void init(){
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)p[j]=q[j]=0;
		int s=0;
		vector<int>v;
		for(int j=i;j<=n;j++){
			if(p[a[j]]){
				for(int u=v.size()-1;u>=0;u--){
					if(v[u]==a[j])
						while(v.back()!=a[j])v.pop_back();
				}
			}
			
			v.push_back(a[j]),p[a[j]]=1;
		}
		for(int j:v){
			if(!q[j])q[j]=1,ans[j]++;
//			cout<<j<<' ';
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	init();
	return  0;
}
/*
hard!!!!
Maybe 24pts.
100+100+100+24=324?
Can I have 1=?
i will lose.
O(n^3)
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
