#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,a[N];
char c[N],s[N];
int ans=0,tot=0,b[N]/*将a数组合并后的数组*/;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
		if(i==1){
			b[++tot]=a[i];
			s[tot]=c[i];
			continue;
		}
		if(c[i]==c[i-1]) b[tot]+=a[i];
		else{
			b[++tot]=a[i];
			s[tot]=c[i];	
		}
	}
//	for(int i=1; i<=tot; i++) cout<<b[i]<<' '<<s[i]<<endl;
	if(tot==1){
		cout<<0;
		return 0;
	}
	int l=1,r=tot;
	while(l<r){
//		cout<<l<<' '<<r<<' '<<ans<<endl;
		if(s[l]==s[r]){
			if(b[l]<b[r]){
				b[r]-=b[l];
				l++;
			}
			else if(b[l]==b[r]){
				l++;
				r--;
			}
			else{
				b[l]-=b[r];
				r--;
			}
		}
		else{
			if(b[l]<b[r]){
				b[r]-=b[l];
				ans+=b[l];
				l++;
			}
			else if(b[l]==b[r]){
				ans+=b[l];
				l++;
				r--;
			}
			else{
				ans+=b[r];
				b[l]-=b[r];
				r--;
			}
		}
//		cout<<l<<' '<<r<<' '<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
