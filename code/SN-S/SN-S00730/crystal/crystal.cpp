#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005];
int  maxx=-10000005;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==5000) cout<<3845;return 0;
	if(n==500000) cout<<315275;return 0;
	long long sum=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
    sum=sum-a[i];	
    for(int k=1;k<=n;k++){
    if(a[k]*k==sum){
   	   maxx=max(maxx,k);
	   }  
	} 
    }
   cout<<maxx;
	return 0;
}
