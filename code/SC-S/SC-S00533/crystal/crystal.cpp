#include<bits/stdc++.h>
using namespace std;
const long long MAXN=10000005;
long long n,m;
long long a[MAXN];
long long b[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	int sum[n+15];
	for(int i=1;i<=n;i++){
		sum[i]=0;
		for(int j=1;j<=n;j++){
			sum[i]+=abs(a[i]-a[j]);
		}
		b[i]=sum[i];
	}
	sort(sum+1,sum+n+1);
	
	int s;
	for(int i=1;i<=n;i++){
		if(b[i]==sum[1]){
			s=i;
			break;
		}
	}
	int d[n+15];
	for(int i=1;i<=n;i++){
		d[i]=abs(a[s]-a[i]);
	}
	sort(d+1,d+n+1);
	
	
	int rest=m;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(rest>0){
			rest-=d[i];
			ans++;
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;

}