#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long n,m,sum=0,ans=1,cs=0;
long long a[500006],b[500006];
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			sum++;
			if(sum==n){
				ans=m/2;
				if(ans>=n){
					cout<<n;
				}else{
					cout<<ans;
				}
				return 0;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		if(i+1<=n){
//		b[i]=a[i+1]-a[i];
//		cs+=1;
//	}
//	}
//	for(int i=1;i<=cs;i++){
//	  
//	}
// -55,-55,40,1,2,3,4,5
	return 0;
	
}
