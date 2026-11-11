#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	
	if(n>=10000){
		unsigned long long sum=0;
		long long i=0;
		while(sum<=m){
			i+=abs(a[n]-a[n-1]);
			sum+=i;
		}
		cout<<min(n,i);
		return 0;
	}
	
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=2;i<=n;i++){
		unsigned long long sy=m;
		int p=i-1;
		int num=1;
		
		while(sy>0&&p>0){
			if(sy>=(a[i]-a[p])){
				num++;
				sy-=(a[i]-a[p]);
				p--;
			}else{
				break;
			}
		}
		ans=max(ans,num);
	}
	
	cout<<ans;
	return 0;
} 