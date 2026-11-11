#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],ans,sum,ans2;
char c[200010];
//string s="";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int l=1,r=n;
	while(l<=r&&l<=n&&r>=1){
		if(a[l]>a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else if(a[l]==a[r]){
			if(c[l]!=c[r])ans+=a[l];
			a[l]=0,a[r]=0;
			l++,r--;
		}
		else{
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
