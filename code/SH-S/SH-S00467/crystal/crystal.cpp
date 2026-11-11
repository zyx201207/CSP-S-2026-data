#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;
long long n,m,a[500010],ans,z[500010];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			long long num=0,sum=1;
			for(int j=i-1;j>=1;j--){
				num=num+(a[i]-a[j]);
				if(num>m) break;
				sum++;
			}
			ans=max(ans,sum);
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			z[i]=z[i-1]+(a[1]-a[i]);
		}
		for(int i=1;i<=n;i++){
			long long v=i;
			long long l=i,r=n;
			while(l<=r){
				long long mid=(l+r)/2;
				long long bw=m+(a[1]-a[i])*(mid-i)+z[i];
				if(bw>=z[mid]){
					l=mid+1;
					v=mid;
				}
				else r=mid-1;
			}
			v=v-i+1;
			ans=max(ans,v);
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
