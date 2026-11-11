#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXN 2000010
int c,t;
int n;
LL d;
LL x[MAXN];
struct node{
	int num;
	int age;
};
queue<node> Q;
LL cnt;
LL age;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i =1;i<=n;i++){
			cin>>x[i];
		}
		LL ans=0;
		for(int i =1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				while(!Q.empty()){
					Q.pop();
				}
				age=0;
				cnt=0;
				Q.push({i,0});
				while(!Q.empty()){
					node tmp=Q.front();
					Q.pop();
					if(tmp.num==j){
						if(!age){
							age=tmp.age;
							cnt++;
						}
						else if(age==tmp.age){
							cnt++;
						}
						else{
							break;
						}
					}
					int v=1;
					while(x[tmp.num+v]-x[tmp.num]<=d&&tmp.num+v<=n){
						Q.push({tmp.num+v,tmp.age+1});
						v++;
					}
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
