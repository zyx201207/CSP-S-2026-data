#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,z,d,x,y,ans,fl,a[2000010];
int js(int x,int y){
	int ans=0;
	z=x;
	while(z<=y){
	    for(int i=y;i>=z;i--)
	        if(a[i]-a[z]<=d){
	        	ans++;z=i;
			}
	    if(z==y)return ans;	
	}
	return ans;	
}
void bfs(int t,int s,int ss,int g){
	if(s>ss)return ;
	if(fl)return ;
	if(t==x+1){
		if(s==ss)z++;
		if(z>2){
			fl=1;return ;
		}
		return ;
	}
	for(int i=s+1;i<=n;i++){
	    if(a[i]-a[s]<=d){
	    	bfs(t+1,i,ss,g+1);
		}
		
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
    	cin>>n>>d;ans=0;z=0;
    	for(int i=1;i<=n;i++)cin>>a[i];
    	if(c==11||c==12){
    		if(a[3]-a[1]>d)cout<<0<<"\n";
    		else cout<<n-3<<"\n";
		}
		else if(c<=6){
			for(int i=1;i<=n;i++)
		    for(int j=i+3;j<=n;j++){
		    	x=js(i,j);
		    	if(x!=0)fl=0,z=0,bfs(1,i,j,0);
		    	if(z==2)ans++;
			}
			cout<<ans<<"\n";
		}
		else{
		    x=1;y=1;
        	for(int x=1;x<=n-3;x++){
        		y=x+3;
        		if(a[x+1]-a[x]<=d&&a[x+3]-a[x+1]<=d&&
    			a[x+2]-a[x]<=d&&a[x+3]-a[x+2]<=d&&a[x+3]-a[x]>d)
    				ans++;
	    	}
		    cout<<ans<<"\n";
		}
	}
}
