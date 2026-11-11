#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],cnt,mid,ans,l,r,s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	l=1,r=n;
	mid=(cnt+1)/2;
	while(s<=mid){
		if(r-l==1){
			if(c[l]!=c[r])ans+=min(a[r],a[l]);
			break;
		}
		if(c[l]!=c[r]){
			if(a[l]<=a[r]) ans+=a[l],a[r]-=a[l],l++,s+=a[l];
			else ans+=a[r],a[l]-=a[r],r--;
		}
		else{
			if(a[l]<=a[r])a[r]-=a[l],l++,s+=a[l];
			else a[l]-=a[r],r--;
		}
	}
	cout<<ans;
	return 0;
}

