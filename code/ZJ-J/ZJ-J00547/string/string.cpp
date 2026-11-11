#include<bits\stdc++.h>
using namespace std;
int n;
int a[200010];
char s[200010];
long long t,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		t+=a[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(s[l]!=s[r]){
			ans+=min(a[l],a[r]);
		}
		if(a[l]<a[r]){
			a[r]-=a[l];
			a[l]=0;
		}else{
			a[l]-=a[r];
			a[r]=0;
		}
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans<<endl;
	return 0;
}
