#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N];
long long ans=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long c=a[2]-a[1];
	bool f=1;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			f=0;
			break;
		}
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			long long sum=0,cnt=1;
			for(int j=i-1;j>=1;j--){
				if(sum+a[i]-a[j]<=m){
					sum+=a[i]-a[j];
					cnt++;
				}else break;
			}
			ans=max(ans,cnt);
		}
	}else{
		long long x=0,b=c,cnt=1;
		while(x+b<=m){
			x+=b;
			b+=c;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}