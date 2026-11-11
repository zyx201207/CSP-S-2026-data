#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long sum=(a[n]-a[1])/(n-1);
	long long l=a[1],r=a[n],mid=(l+r)/2;
	int ans=(sum+mid-l)*2;
	if(m>=ans){
	cout<<ans<<"\n";
	return 0;
	}else {
		int a=(n/2)*10;
		int b=a%10;
		int c=(b-a)/10;
		int val=(m/2)*10;
		int pre=val%10;
		int s=(pre-val)/10;
		int y=0;
		while(s>sum){
			int j=s-sum;
			y++;
			int s=j;
			
	}
		int j=2*y;
		cout<<j<<"\n";
	}
	return 0;
}
