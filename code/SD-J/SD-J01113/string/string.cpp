#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,ans,len,l=1,r,x;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	len/=2;
	r=n;
	while(l<=r){
		x=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=x;
		a[l]-=x;
		a[r]-=x;
		if(a[l]<=0) l++;
		if(a[r]<=0) r--;
	}
	cout<<ans;
	return 0; 
} 
