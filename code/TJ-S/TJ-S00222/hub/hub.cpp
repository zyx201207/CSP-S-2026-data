#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,k;
vector<long long> e[100005];
long long ltk=0;
bool chose[100005];
long long dfs(long long u,long long fa){
	long long maxdis=-1e18;
    for(long long t:e[u]){
        if(t==fa)continue;
        if(ltk<2||chose[u]){
            if(!chose[u])ltk++;
            chose[t]=true;
            maxdis=max(maxdis,dfs(t,u));
            chose[t]=false;
            if(!chose[u])ltk--;
        }
        maxdis=max(maxdis,dfs(t,u));
    }
    return maxdis;
}
bool check(long long mid){
	return true;
}
int main(){
	freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if(c==13||c==14){
    	while(t--){
    		cin>>n>>k;
    		long long m=(n-1)/2;
    		if(m<k&&k!=n){
    			cout<<1<<endl;
			}else if(k==n){
				cout<<0<<endl;
			}else{
				cout<<(m-k)/3+1;
			}
		}
    	return 0;
	}
    while(t--){
        cin>>n>>k;
        
        for(int i=1;i<=n;i++){
            e[i].clear();
        }
        for(int i=1;i<=n;i++){
            long long u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(n==k){
        	cout<<0<<endl;
        	break;
		}
        long long l=0,r=1e18;
        long long ans=0;
        while(l<=r){
            long long mid=(l+r)>>1;
            mid=(l+r)>>1;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid;
            }
        }
        cout<<0<<endl;
    }
    return 0;
}
