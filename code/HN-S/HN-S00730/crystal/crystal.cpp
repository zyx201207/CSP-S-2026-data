#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
struct P{
	long long x,res;
}sum[N];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	sum[1]={1,0};
	for(int i=2;i<=n;i++){
		if(sum[i-1].res+(i-sum[i-1].x)*(a[i]-a[i-1])<=m){
			sum[i]=P{sum[i-1].x,sum[i-1].res+(i-sum[i-1].x)*(a[i]-a[i-1])};
		}else{
			long long top=sum[i-1].x-1;
			long long tim=sum[i-1].res+(i-sum[i-1].x)*(a[i]-a[i-1]);
			while(tim>m){
				tim=tim-(a[i]-a[++top]);
			}
			sum[i]=P{top+1,tim};
		}
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		ans=max((long long)(i-sum[i].x+1ll),ans);
	}
	cout<<ans<<"\n";
	return 0;
} 

