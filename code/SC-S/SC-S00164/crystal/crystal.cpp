#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],ans=1,s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s[1]=0;
	sort(a+1,a+1+n);
	if(n<=10000){
		for(long long i=1;i<=n;i++){
		int k=0;bool b=0;
		for(long long j=i;j>=1;j--){
			k+=a[i]-a[j];
			if(k<=m){                                                                            
				continue;
			}
			ans=max(ans,i-j);
			b=1;
			break;
		}
		if(b==0){
			ans=max(ans,i);
		}
	}
	cout<<ans;
	return 0;
	}
	
	for(long long i=2;i<=n;i++){
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
		if(s[i]>m){
			cout<<i-1;
			//return 0;
			return 0;
		}
	}
//	for(long long i=n;i>=1;i--){
//		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
//		if(s[i]>m){
//			cout<<max(ans,n-i+1);
//			return 0;
//		}
//	}
	cout<<n;
	return 0;
}