#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int main(int argc,char**argv){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned int n=5e5;
	unsigned long long m=1e18;
	cin>>n>>m;
	signed long long a[n];//1e12
	for(unsigned int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	bool isA=true;
	for(unsigned int i=1;i<n;i++)
		if(a[i]!=a[i-1])isA=false;
	if(isA)cout<<n;
	else{
		unsigned int ans=1;
		for(unsigned int i=n-1;i;i--){
			if(i<n-1&&a[i]==a[i+1])continue;
			unsigned int r=m;
			for(unsigned int j=i;j<n&&r;j--){
				if(a[i]-a[j]>r)break;
				else r-=a[i]-a[j];
				ans=max(ans,i-j+1);
			}
		}
		cout<<ans;
	}
}