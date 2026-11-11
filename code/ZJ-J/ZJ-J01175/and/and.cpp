#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],x=2,mx=0;
int vis[200005],cnt=0,f=0,cct=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=30;i++){
		x*=2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(x){
		if(f==0){
			cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]%(x*2)>=x)cnt++;
			}
			if(cnt>=m){
				f=1;	
				mx+=x;
				for(int i=1;i<=n;i++){
					if(a[i]%(x*2)>=x)vis[i]=1;
				}
			}
		}
		else if(f==1){
			cct=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==1){
					if(a[i]%(x*2)>=x){
						cct++;
					}
		
				}
			}
			if(cct>=m){
				mx+=x;
				for(int i=1;i<=n;i++){
					if(vis[i]==1&&a[i]%(x*2)<x){
						vis[i]=0;
					}
				}
			}
		}
		x/=2;
	}
	cout<<mx;
	return 0;
}
