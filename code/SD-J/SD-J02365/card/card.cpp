#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+5;
int n,m,a[N],f[300005],ans,sum[300005];
stack<int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				q.push(a[j]);
				f[a[j]]=1;
			}
			else{
				while(q.top()!=a[j]){
					int p=q.top();
					q.pop();
					f[p]=0;
				}
			}
		}
		while(!q.empty()){
			sum[q.top()]++;
			q.pop();
		}
		memset(f,0,sizeof f);
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}

