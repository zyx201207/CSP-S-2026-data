#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=2e6+10;
namespace STD{
	int n,p[N],k,dis[N];
	int h=1,t=0,q[N],cnt[N];
	void work(){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>p[i];
			dis[i]=INT_MAX;
		}
		h=1,t=0;
		dis[1]=0;
		q[++t]=1;
		cnt[0]=1;
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
		for(int i=2;i<=n;i++){
			while(h<=t&&p[q[h]]+k<p[i]) h++;
			if(h>t){
				break;	
			}
			dis[i]=dis[q[h]]+1;
			q[++t]=i;
		//	cout<<dis[i]<<" ";
			cnt[dis[i]]++;;
		}
		//cout<<"\n";
		int ans=0;
		for(int i=1;i<=n;i++){
		//	cout<<i<<" ";
			if(dis[i]==INT_MAX) break;			
			int j=i;
			while(dis[j]==dis[j+1]){
				j++;
			}

			//cout<<j<<"\n";
			if(cnt[dis[j]]==2){
				ans+=cnt[dis[j]-1]*cnt[dis[j]+1];
			}
			i=j;
		}
		for(int i=1;i<=n;i++){
			if(dis[i]!=INT_MAX)
			cnt[dis[i]]=0;	
		}
		cout<<ans<<"\n";
	}
}
void rw(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c,T=1;cin>>c>>T;
	while(T--) STD::work();

	return 0;
}


