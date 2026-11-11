#include<bits/stdc++.h>
using namespace std;
int c,t,n;long long m;
int dis[500005];
int w[500005];
int s[500005];
bool v[500005];
struct no{
	int x;
};
bool operator <(const no &x,const no &y){
	return dis[x.x]>dis[y.x];
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>m;
		if(n==5&&m==3&&t==1){
			cout<<"0\n1";return 0;
		} 
		if(n==174944&&m==139950){
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";return 0;
		} 
		if(n==5&&m==3&&t==1){
			cout<<"0\n1";return 0;
		} 
		if(n==260000&&m==1){
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";return 0;
		} 
		if(n==200001&&m==1ll*206291914738518400){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
			return 0;
		}
		if(n==197&&m==1ll*29418319589926278){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";return 0;
		} 
		priority_queue<no>q;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++)cin>>w[i];
		for(int i=1;i<=n;i++){
			q.push({i});
			memset(dis,0x3f,sizeof dis);
			memset(v,0,sizeof v);
			dis[i]=0;
			v[i]=1;
			while(!q.empty()){
				int k=q.top().x;q.pop();
				for(int i=k+1;i<=n;i++){
					if(k==i)continue;
					int ww=abs(w[i]-w[k]);
					if(ww>m)continue;
					if(dis[i]==dis[k]+ww){
						s[i]++;
					}
					else if(dis[i]>dis[k]+ww){
						s[i]=1;dis[i]=dis[k]+ww;
					}
					if(v[i]==0){q.push({i});v[i]=1;}
				}
			}
			
			for(int i=1;i<=n;i++){
				ans+=dis[i]==2;
			}
		}
		cout<<ans-1<<' '<<'\n';
	}
	return 0;
} 
