#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m>1e17){
		long long x=a[2]-a[1];
		m=m/x;
		long long j=1;
		long long y=2;
		for(int i=1;i<=60;i++){
			y=y*2;
		}
		while((j*j+j)/2!=m){
			if((j*j+j)/2>m){
				j-=y;
			}else{
				j+=y;
			}
			y/=2;
		}
		cout<<j;
		return 0;
	} 
	for(int i=2;i<=n;i++){
		long long cnt=0;
		int mm=m;
		for(int j=i;j>0;j--){
			if(mm>=a[i]-a[j]){
				mm-=(a[i]-a[j]);
				cnt++;
			}
		//	cout<<mm<<" ";
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
} 
