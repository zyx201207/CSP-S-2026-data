#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
bool flag[N]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	if(m==1){//6
		for(int i=1;i<=n;i++){
			ans=max(a[i]&a[i],-1000);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){//7
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){//11 12
		for(int i=1;i<=n;i++){
			for(int i=1;i<=n;i++){
				flag[i]=0;
			}
			flag[i]=1;
			if(i==n-1){
				flag[n]=1,flag[1]=1;
				ans=a[n]&a[1];
				for(int i=1;i<=n;i++){
					if(flag[i]!=1){
						ans=max(ans&a[i],-1000);
					}
				}				
			}else if(i==n){
				flag[1]=1,a[2]=1;
				ans=a[1]&a[2];
				for(int i=1;i<=n;i++){
					if(flag[i]!=1){
						ans=max(ans&a[i],-1000);
					}
				}				
			}
			else{
				flag[i+1]=1,flag[i+2]=1;
				ans=a[i+1]&a[i+2];
				for(int i=1;i<=n;i++){
					if(flag[i]!=1){
						ans=max(ans&a[i],-1000);
					}
				}				
			}

		}
		cout<<ans;
		return 0;
	}
    for(int i=1;i<=n;i++){//8 9 10
    	for(int j=i+1;j<=n;j++){
    		ans=max(a[i]&a[j],-1000);
		}
	}
	cout<<ans;
	return 0;
}

