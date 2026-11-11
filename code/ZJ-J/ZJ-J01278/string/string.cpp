#include<bits/stdc++.h>
using namespace std;
int n,a[200005],l,r;
char c[200005];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1;
	r=n;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]==a[r]) l++,r--;
			else if(a[l]<a[r]) a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}
		else{
			if(a[l]==a[r]) sum+=a[l],r--,l++;
			else if(a[l]<a[r]) a[r]-=a[l],sum+=a[l],l++;
			else a[l]-=a[r],sum+=a[r],r--;
		}
	}
	cout<<sum;
	return 0;
}
