#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char b[200010];
long long sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	int l=1,r=n;
	long long cnt=0;
	while(l<=r&&cnt<=sum/2){
		int fw=min(a[l],a[r]);
		a[l]-=fw;
		a[r]-=fw;
		cnt+=fw;
		if(b[l]!=b[r]) ans+=fw;
		if(!a[l]) l++;
		if(!a[r]) r--;
	}
	cout<<ans;
	return 0;
}