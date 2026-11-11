#include<bits/stdc++.h>
using namespace std;
long long a[6000000];
long long m;
long long n,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int x=0;
	a[x]+=a[x+2]-a[x];
	a[x+1]+=a[x+2]-a[x+1];
	int yx=m-a[x+2]-a[x]+a[x+2]-a[x+1];
	int yy=a[x+3]-a[x+2]+a[x+3]-a[x+1]+a[x+3]-a[x];
	if(yy<=yx){
		a[x]+=a[x+3]-a[x];
		a[x+1]+=a[x+3]-a[x+1];	
		a[x+2]+=a[x+3]-a[x+2];
	} 
	for(int i=0;i<n;i++){
		long long p=1;
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				p++;
			}
		}
		ans=max(ans,p);
	}
	cout<<ans;
	return 0;
} 