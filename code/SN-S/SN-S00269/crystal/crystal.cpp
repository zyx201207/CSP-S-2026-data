#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[50015];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long l=0,r=1;
	long long ans=1,sum=0;
	while(true){
		if(r==n){
			break;
		}
		if(l==n)break;
		for(long long i=l;i<=r;i++){
			sum+=a[r]-a[i];
		}
		if(sum>m){
			if(ans<r-l)ans=r-l;
			l++;
			r--;
		}else{
			r++;
		}
		sum=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
