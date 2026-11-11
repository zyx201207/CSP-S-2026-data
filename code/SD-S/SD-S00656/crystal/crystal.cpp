#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],lt,rt,mid,ans;
bool check(long long x){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(x<a[i])break;
		sum+=(x-a[i]);
	}
	return (sum<=m);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    lt=9e18,rt=-9e18;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	lt=min(lt,a[i]);
    	rt=max(rt,a[i]);
	}
	sort(a+1,a+1+n); 
	while(lt<=rt){
		mid=(lt+rt)/2;
		if(check(mid)){
			lt=mid+1;
		}else{
			rt=mid-1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=lt-1)ans++;
	}
	cout<<ans;
	return 0;
}

