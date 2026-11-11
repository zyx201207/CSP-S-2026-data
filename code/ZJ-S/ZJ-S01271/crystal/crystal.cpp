#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],b[1000000],i;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=n;i>0;i--){
		long long use=m,stand=a[i],num=0;
		long long f=i;
		while(use>=0&&f>=1){
			use-=stand-a[f];
			f-=1;	
			num+=1;
			if(use>=0) b[i]=num;
		}
	}
	sort(b+1,b+n+1);
	cout<<b[n];
	return 0;
}
