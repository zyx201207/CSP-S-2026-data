#include<iostream>
#include<cstdio>
using namespace std;
const int N=2005;
long long x[N];
int dist[N];
int cnt[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("migrate.in","r",stdin);
    //freopen("migrate1.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
    	int n;
    	long long d;
    	cin>>n>>d;
    	for(int i=1;i<=n;i++)
    	cin>>x[i];
    	long long ans=0;
    	for(int u=1;u<=n;u++){
    		for(int i=1;i<=n;i++){
    			dist[i]=1e9;
    			cnt[i]=0;
			}
			dist[u]=0;
			cnt[u]=1;
			int l=u;
			for(int i=u+1;i<=n;i++){
				while(x[i]-x[l]>d)l++;
				int mn=1e9;
				for(int j=1;j<i;j++)
				if(dist[j]+1<mn)mn=dist[j]+1;
				dist[i]=mn;
				int s=0;
				for(int j=l;j<i;j++)
				if(dist[j]+1==mn){
					s+=cnt[j];
					if(s>2)s=3;
					
				}
				cnt[i]=s;
				if(cnt[i]==2)ans++;
			}
		}
		cout<<ans<<'\n';
		
	}
	return 0;
	
}
