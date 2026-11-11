#include <bits\stdc++.h>
using namespace std;
long long a[20005];
int n,m;
long long ans,ans1;
bool flag=true;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m=1&&flag){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		} flag=false;
	}else if(m==n&&flag){
		for(int i=1;i<=n;i++){
			ans=ans|a[i];
		}flag=false;
	}
	else if(m==2&&flag){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]|a[j]);
			}
		}flag=false;
	}
	
	else if(m=n-1&&flag){
		for(int i=1;i<=n;i++){
			for(int j=1;j!=i;j++){
				ans1=ans1|a[j];
			}
			for(int j=i+1;j<=n;j++){
				ans1=ans1|a[j];
			}
			ans=max(ans,ans1);
		}flag=false; 
	}
	else{
		bool you1=false,you2=false,you3=false;
		for(int i=1;i<=n;i++){
			if(a[i]==(long long)1) you1=true;
			if(a[i]==(long long)2)you2=true;
			if(a[i]==(long long)3)you3=true;
		}
		if(you3) ans=3;
		else{
			if(you2&&you1) ans=3;
			else if(you2) ans=2;
			else ans=1;
		}
	}if(n<=20&&flag){
		if(m==3&&flag){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int p=j+1;p<=n;p++){
					ans=max(ans,a[i]|a[j]|a[p]);
				}
			}
		}flag=false;
	}
	if(m==4&&flag){
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int p=j+1;p<n;p++){
					for(int o=p+1;o<=n;o++){
						ans=max(ans,a[i]|a[j]|a[p]|a[o]);
					}
				}
			}
		}flag=false;
	}
	}
	cout<<ans;
	return 0;
} 
