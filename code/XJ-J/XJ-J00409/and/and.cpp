#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005][35],q[35],re[200005],ans;
bool vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	long long x,cnt=0;
    	cin>>x;
    	while(x!=0){
    		if(x%2==1)
    			a[i][cnt]=1;
    		x/=2;
			cnt++;	
		}
	}
	q[0]=1;
	for(int i=1;i<=32;i++){
		q[i]=q[i-1]*2;
	}
	for(int i=30;i>=0;i--){
		long long cnt1=0,t=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				cnt1+=a[j][i];
				if(!a[j][i]){
					re[++t]=j;
				}
			}
		}
			
		if(cnt1>=m){
			ans+=q[i];
			for(int j=1;j<=t;j++)
				vis[re[j]]=1;
		}
			
	}	
	cout<<ans;
	return 0;
}