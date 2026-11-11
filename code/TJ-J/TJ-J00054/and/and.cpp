#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MM=2*1e5+100;
long long a[MM];
bool pdpd=0;
long long ans;
long long apt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=20;i++){
		apt*=2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>3) pdpd=1;
	}
	if(m==1 || !pdpd){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
			
		}
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,(a[i]&a[j])&a[k]);
				}
			}
		}
	}
	else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int kk=k+1;kk<=n;kk++) 
						ans=max(ans,((a[i]&a[j])&a[k])&a[kk]);
				}
			}
		}
	}
	else if(m==n-1){
		
		for(int i=1;i<=n;i++){
			long long ttt=apt-1;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ttt=ttt&a[j];
			}
			ans=max(ans,ttt);
		}
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}
	cout<<ans; 
	return 0;
}
