#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long m,a[2000010],l[2000010];
struct node{
	int id;
	long long num;
};
struct nodeq{
	long long v;
	friend bool operator <(nodeq x,nodeq y){
		return x.v>y.v;
	}
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		long long ans=0;
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int x=1;x<n;x++){
			queue<node>q;
			for(int i=1;i<=n;i++) l[i]=0; 
			q.push({x,0});
			l[0]=1;
			for(int i=x+1;i<=n;i++){
				while(!q.empty() and a[i]-a[q.front().id]>m){
					l[q.front().num]--;
					q.pop();
				}
				if(q.empty()) break;
				q.push({i,q.front().num+1});
				l[q.front().num+1]++;
				if(l[q.front().num]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
