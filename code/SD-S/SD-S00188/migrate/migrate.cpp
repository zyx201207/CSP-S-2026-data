#ifdef icop
#define nofl
#endif
#ifdef allallallall
//jimmy
//long long,momery,file,flush
#endif
#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e6;
long long n,d;
void clear(){//clear;
}
int dis[N+5];
long long cnt[N+5];
long long x[N+5];
void bfs(int s){
	for(int i=1;i<=n;i++){
		dis[i]=n*2;
		cnt[i]=0;
	}
	cnt[s]=1;
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=u+1;i<=n;i++){
			if(abs(x[i]-x[u])>d){
				break;
			}
			if(dis[i]>dis[u]+1){
				dis[i]=dis[u]+1;
				cnt[i]=cnt[u];
					q.push(i);
//					cout<<u<<" "<<i<<"1\n";
			}else if(dis[i]==dis[u]+1){
//					cout<<u<<" "<<i<<"2\n";
//					q.push(i);
				cnt[i]+=cnt[u];
			}
		}
		for(int i=u-1;i>0;i--){
			if(abs(x[i]-x[u])>d){
				break;
			}
			if(dis[i]>dis[u]+1){
				dis[i]=dis[u]+1;
				cnt[i]=cnt[u];
					q.push(i);
//					cout<<u<<" "<<i<<"1\n";
			}else if(dis[i]==dis[u]+1){
//					cout<<u<<" "<<i<<"2\n";
//					q.push(i);
				cnt[i]+=cnt[u];
			}
		}
	}
}
void tmin(){
	clear();
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<cnt[j]<<" "<<dis[j]<<"\n";
			if(cnt[j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	#ifndef nofl
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	#endif
	int c,t;
	cin>>c>>t;
	while(t--){
//		cout<<"t:"<<t<<"\n";
		tmin();
	}
}

