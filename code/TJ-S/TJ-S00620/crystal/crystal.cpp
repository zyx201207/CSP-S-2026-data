#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
int ans=1,p=0,q=0;
long long a[100005],b[100005]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(m==0||n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==i){
			p++;
		}
		if(i>2&&a[i-1]-a[i-2]==a[i]-a[i-1]){
			q++;
		}
	}
	int z=a[2]-a[1];
	if(z<0){
		z*=-1;
	}
	if(p==n||q+1==n){
		for(long long i=1,j=1;i<=n;i+=j*z,j++){
			if(i>m){
				cout<<j-1;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1,v=0;i<=n;i++){
		if(a[i]<=0||v==1){
			a[i]+=a[1]+1;
			v=1;
		}
		b[i]=a[i]+b[i-1];
		//sum=a[j]*(j-i+1)-b[j]+b[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sum=a[j]*(j-i+1)-b[j]+b[i-1];
			if(sum>m){
				ans=max(j-i,ans);
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
