#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200100],n,s[200100],len,ans,cnt;
char c[200100];
string k;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
		for(int j=1;j<=a[i];j++){
			k=k+c[i];
		}
	}
	len=s[n];
	int l=1,r=n,k1=a[1],k2=a[n];
	for(int i=1;i<=len/2;){
		if(i>s[l]) l++;
		if(len-i+1<s[r-1]) r--;
		if(i+min(k1,k2)>len/2){
			if(c[l]!=c[r]) ans+=len/2-i+1;
			break;
		}
		if(k1<k2){
			if(c[l]!=c[r]) ans+=min(k1,k2);
			i+=k1;
			k2-=k1;
			k1=s[l+1]-s[l];
		}else if(k1==k2){
			if(c[l]!=c[r]) ans+=min(k1,k2);
			i+=k1;
			k2=s[r-1]-s[r-2];
			k1=s[l]-s[l-1];
		}else{
			if(c[l]!=c[r]) ans+=min(k1,k2);
			i+=k2;
			k1-=k2;
			k2=s[r-1]-s[r-2];
		}
	}
	cout<<ans;
}