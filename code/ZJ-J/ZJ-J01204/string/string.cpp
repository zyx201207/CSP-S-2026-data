#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum,b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		b[i]=int(c-'a'+1);
	}
	int l=0,r=n+1,ll=0,rr=0;
	while(l<=r){
		if(ll==0)l++,ll+=a[l];
		if(rr==0)r--,rr+=a[r];
		if(l>r)break;
		int t=min(ll,rr);
		if(b[l]!=b[r])sum+=t;
		ll-=t,rr-=t;
	}
	cout<<sum;
	return 0;
}
