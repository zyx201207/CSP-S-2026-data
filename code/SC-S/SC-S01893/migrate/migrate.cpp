#include<bits/stdc++.h>
using namespace std;
int ans[5005][5005];
class nd{
public:
	int x,nw;
	bool operator < (const nd&c)const{
		return ans[nw][x]<ans[nw][c.x];
	}
};
priority_queue<nd> q;
long long a[5005],f[5005][5005];
vector<int> v[5005];
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)v[i].clear();
		memset(ans,0x3f,sizeof(ans));
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)f[i][j]=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>=1;j--)
				if(a[i]-a[j]<=d)
					v[j].push_back(i);
		}
		for(int i=1;i<=n;i++){
			ans[i][i]=0;
			q.push({i,i});
			while(!q.empty()){
				int tp=q.top().x;
				q.pop();
				for(int j:v[tp]){
					if(ans[i][j]==ans[i][tp]+1)f[i][j]+=f[i][tp];
					if(ans[i][j]>ans[i][tp]+1)
						f[i][j]=f[i][tp],
						ans[i][j]=ans[i][tp]+1,
						q.push({j,i}); 					
				}
			}			
		}
		long long cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				cnt+=(f[i][j]==2);
		cout<<cnt<<"\n"; 
	} 
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116
 111111111111111105 333333333333333326 555555555555555547 
 999999999999999989
*/