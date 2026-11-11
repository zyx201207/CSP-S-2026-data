#include<bits/stdc++.h>
using namespace std;
long long ans1,flag;
long long n,m,c,minn;
long long a[500005],b[500005],d;
long long ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(m>0){
	for(long long i=1;i<=n;i++){
		c+=a[i];
	}
	c+=1;
	c/=n;
	for(long long i=1;i<=n;i++){
		if(c>=a[i]&&c<=a[i+1]){
			if(c-a[i]>=a[i+1]-c){
				c=a[i+1];
				d=i+1;
			}
			else{
				c=a[i];
				d=i;
			}	
		}
	}
	for(long long i=d-1;i>=1;i--){
		if(m-a[d]+a[i]>0){
			m-=a[d]-a[i];
			if(flag==1) ans1++;
			else ans++;
		}
		if(m-a[d]+a[i]==0){
			cout<<max(ans+1,ans-ans1);
			return 0;
		}
		if(m-a[d]+a[i]<0){
			cout<<max(ans,ans-ans1-1);
			return 0;
		}
	}
	if(m>0){
		flag=1;
		for(long long i=1;i<=d;i++){
			a[i]=c;
		}
	}
	}
	return 0;
}
