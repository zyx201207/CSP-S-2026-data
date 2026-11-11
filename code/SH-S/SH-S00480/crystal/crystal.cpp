#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long p[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag=2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=0;
	}
	sort(a+1,a+n+1);
	long long ans=0;
	if(flag==2){
		long long c=a[n]-a[n-1];
		for(long long i=c;i<=a[n]-a[1];i+=c){
			if(m-i<0) break;
			else{
				m-=i;
				++ans;
			}
		}
		cout<<ans+1;
	}
	else{
		for(int i=1;i<=n;i++){
			p[i]=a[i]-a[i-1];
		}
		
		for(int i=2;i<=n;i++){
			if(a[i]==a[1]) continue;
			long long m1=m;
			long long an=0;
			for(int j=i-1;j>=1;j--){
				if(m1-a[i]+a[j]>=0){
					m1=m1-a[i]+a[j];
					an++;
				}
				else break;
			}
			ans=max(ans,an);
		}
		cout<<ans+1;
	}
}
