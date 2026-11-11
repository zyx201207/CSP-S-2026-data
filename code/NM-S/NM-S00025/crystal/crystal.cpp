#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+10;
long long a[N];
long long cha[N];
long long nm[N];
long long pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	//cout<<n<<" "<<m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if((mid-i+1)*a[mid]-(pre[mid]-pre[i-1])<=m){
				ans=max(ans,mid-i+1);
				l=mid+1;
			}
			else
			r=mid-1;
		}
	}
	/*for(int i=1;i<=n;i++)
	printf("%d:%lld %lld %lld\n",i,nm[i],cha[i],pre[i]);*/
	cout<<ans;
	return 0; 
}
/*
5 5 
1 2 4 8 9

5 8 
-3 1 2 2 7
*/
