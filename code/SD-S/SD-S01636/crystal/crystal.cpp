#include<bits\stdc++.h> 
using namespace std;
long long a[500005];
long long ans,sum;
unsigned long long n,m;
int ll=1;
void find(long long x){
	long long l=ll,r=x,mid;
	while(l<r){
		mid=l+(r-l)/2;
		long long sum=0;
		for(int i=mid;i<=x;i++){
			sum+=abs(a[x]-a[i]);
			if(sum>m){
				l=mid+1;
				break;
			}
		}
		if(sum<=m)r=mid;
	}
	ll=l;
	if(x-l+1>ans)ans=x-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		for(long long i=1;i<=n;i++){
			find(i);
		}
		cout<<ans;
	}
	else{
		long long bc=abs(a[2]-a[1]);
		long long i;
		if(n%2==0){
			for(i=1;i<=n;i++){
				sum+=1ll*i*(bc)/2;
				ans++;
				if(sum>m){
					break;
				}ans+=1;
				sum+=1ll*i*(long long)ceil((double)bc/2);
				if(sum>m){
					break;
				}ans+=1;
			}
			cout<<ans+1;
		} 
		else{
			for(i=1;i<=n;i++){
				sum+=1ll*i*bc;
				if(sum>m){
					break;
				}ans++;
				sum+=1ll*i*bc;
				if(sum>m){
					break;
				}
				ans++;
			}
			cout<<ans+1;
		}
	}
	return 0;
}

