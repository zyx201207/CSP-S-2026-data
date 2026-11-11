#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],m,mx,mi=1000000000000000001;
long long po,ans,co[1000010],bs;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	//scanf("%lld",&n,&m);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		//scanf("%d",a[i]);
		cin>>a[i];
		if(a[i]>mx)mx=a[i];
		if(a[i]<mi)mi=a[i];
	}
	sort(a,a+n);
	a[n]=1000000000000000001;
	for(long long i=mi;i<=mx;i++){
		long long cost=0,small=0,mm=0;
		for(int j=0;j<n;j++){
			if(a[j]<=i&&a[j+1]>i)mm=j;
		}
		for(int j=mm;j>=0;j--){
			cost+=i-a[j];
			if(cost>m){
				cost-=i-a[j];break;
			}
			small++;
		}
		if(small>ans){
		po=i;
		ans=small;
		}
	}
	printf("%lld",ans);
	return 0;
} 