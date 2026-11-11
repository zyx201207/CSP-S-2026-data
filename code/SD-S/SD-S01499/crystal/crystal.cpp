#include<bits/stdc++.h>
using namespace std;
long long a[500010],d[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long sum=0,cnt=0;
		for(int j=i;j<=n;j++){
			if(cnt+abs(d[j]*sum)>m){
				break;
			}
			else{
				cnt+=abs(d[j]*sum);
				sum++;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
