#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],Max=-1,ans,p;
bool vis[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i = 1;i<=n;i++){
			Max=max(Max,a[i]);
		}
	}
	else if(m==2){
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				Max=max(Max,a[i]&a[j]);
			}
		}	
	}
	else if(m==n){
		Max=a[1];
		for(int i = 2;i<=n;i++){
			Max=Max&a[i];
		}
	}
	else if(m==n-1){
		for(int i = 1;i<=n;i++){
			if(i==1){
				p=a[2];
			}
			else{
				p=a[1];
			}
			for(int j = 1;j<=n;j++){
				if(j!=i){
					ans=p&a[j];
					p=a[j];
					
				}
			}
		}
	}
	cout<<Max;
	return 0;
}

