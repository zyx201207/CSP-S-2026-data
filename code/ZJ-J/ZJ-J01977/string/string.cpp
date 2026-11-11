#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,sum,ans,a[N];
char c[N];

signed main(){
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int i=1,j=sum;
	int l=1,r=n;
	while(i<j){
		i=i+min(a[l],a[r]);
		j=j-min(a[l],a[r]);
		if(c[l]!=c[r]) ans=ans+min(a[l],a[r]);
		if(a[l]==a[r]) l++,r--;
		else if(a[l]<a[r]) a[r]-=a[l],l++;
		else a[l]-=a[r],r--;
	}
	cout<<ans;
	return 0;
}
