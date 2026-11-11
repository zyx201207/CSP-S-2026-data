#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5;
struct NODE{
	int x,t;
};
int T;
int n,d;
int x[N];
int book[N][N];
queue<NODE> que;
int ans;
bool c[N];
int a[N];
signed main(void){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T;
	cin>>T;
	while(T--){
		ans=0;
		memset(a,0x7f,sizeof a);
		memset(x,0,sizeof x);
		memset(book,0,sizeof book);
		memset(c,0,sizeof c);
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			que.push(NODE{i,0});
			while(!que.empty()){
				NODE head=que.front(); que.pop();
				for(int j=head.x+1;j<=n;j++){
					if(x[j]-x[head.x]<=d){
						int t=head.t+1;
						if(a[j]>t){
							a[j]=t;
							book[i][j]=1;
							que.push(NODE{j,t});
						}else if(t==a[j]){
							book[i][j]++;
							que.push(NODE{j,t});
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(book[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// [18:19] T3做出来40pts力竭了。。 做不动了。。。 把表一填就跑了 
