#include<bits/stdc++.h>
using namespace std;
int a[600000];
int b[1200000],ans=-1e9;
long long n,m,h=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long l=1,r=n,y=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(m>a[j]-a[i]){
				ans=max(ans,j-i+1);
			}
		}
	}
	//for(int i=1;i<=y;i++){
	//	cout<<b[i]<<" ";
	//}
	cout<<ans;
	return 0;
} 
//It's~okay! 
