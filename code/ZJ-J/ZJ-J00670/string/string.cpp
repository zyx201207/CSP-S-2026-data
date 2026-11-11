#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long a[200010]={};
char c[200010]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			int minn=min(a[l],a[r]);
			a[l]=a[l]-minn;
			a[r]=a[r]-minn;
			ans+=minn;
		}
		else if(c[l]==c[r]){
			int minn=min(a[l],a[r]);
			a[l]=a[l]-minn;
			a[r]=a[r]-minn;
		}
		while(a[l]==0)l++;
		while(a[r]==0)r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}