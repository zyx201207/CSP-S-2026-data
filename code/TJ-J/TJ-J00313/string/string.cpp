#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005];
	char c1[200005];
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c1[i];
	}
	long long ans=0,j=n,i=1;
	long long x=a[i],y=a[j];
	while(i<=j){
		if(c1[i]!=c1[j]){
			ans+=min(x,y);
		}
		if(x>y){
			x-=y;
			y=a[--j];
			continue;
		}
		if(x<y){
			y-=x;
			x=a[++i];
			continue;
		}
		if(x==y){
			x=a[++i];
			y=a[--j];
			continue;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

