#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200010];
char c[200010];
int main(){
	// freopen("E:\\cspj\\down\\string\\string6.in","r",stdin);
	// freopen("E:\\cspj\\down\\string\\string6.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int l=0,r=n+1;
	ll lenl=0,lenr=0,now=0,ans=0;
	while(now<sum){
		if(lenl<lenr){
			l++;
			lenl+=a[l];
		}else{
			r--;
			lenr+=a[r];
		}
		if(c[l]!=c[r]){
			ans+=min(lenl,lenr)-now;
		}
		now=min(lenl,lenr);
	}
	ans=(ans+1)/2;
	cout<<ans;
	return 0;
}