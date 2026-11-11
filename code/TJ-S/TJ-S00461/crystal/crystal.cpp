#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005]={0},b[5000005],maxx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	long long xb=1;
	for(int j=1;j<n;j++){
		if(b[j]>m){
			break;
		}
		long long w=1,mav=m;
		for(int i=j;i<=n;i++){
			if(b[i]*w>mav){
				break;
			}else{
				mav-=b[i]*w;
				w++;
			}
		}
		maxx=max(maxx,w);
	}
	cout<<maxx;
	return 0;
}
