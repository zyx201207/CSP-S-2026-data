#include<bits/stdc++.h>
using namespace std;
long long n,cn,sum,cnt;
long long a[200005];
char z[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>z[i];
	}
	
	long long l=1,r=n;
	while(l<r){
		if(a[l]==0)l++;
		if(a[r]==0)r--;
		long long ff=min(a[l],a[r]);
		if(z[l]!=z[r])cnt+=ff;
		
		a[l]-=ff;
		a[r]-=ff;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
