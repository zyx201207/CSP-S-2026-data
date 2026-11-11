#include<bits/stdc++.h>
#define int long long
using namespace std;
int op,t,n,d,sum;
int a[2000050];
int ans[2000050];
int num[2000050];
struct node{
	int wz,w;
};
queue<node> q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>op>>t;
	while(t--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			memset(ans,-1,sizeof ans);
			memset(num,0,sizeof num);
			q.push({i,0});
			while(!q.empty()){
				int wz=q.front().wz;
				int w=q.front().w;
				q.pop();
				for(int i=wz+1;i<=n&&a[i]-a[wz]<=d;i++){
					if(ans[i]==-1){
						q.push({i,w+1});
						ans[i]=w;
						num[i]=1;
					}else if(ans[i]==w){
						q.push({i,w+1});
						num[i]++;
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				if(num[j]==2)sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}