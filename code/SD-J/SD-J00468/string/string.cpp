#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],ans,tot,r;
char s[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		tot+=a[i];
	}
	r=n;
	for(int i=1;i<=n;){
		if(i>=r)break;
		if(s[i]==s[r]){
			if(a[i]<a[r]){
				a[r]-=a[i];
				i++;
				continue;
			}
			else{
				if(a[i]==a[r]){
					a[r]=0;a[i]=0;
					i++;
					r--;
					continue;
				}
				else{
					a[i]-=a[r];
					r--;
					continue;
				}
			}
		}
		else{
			if(a[i]<a[r]){
				ans+=a[i];
				a[r]-=a[i];
				i++;
				continue;
			}
			else{
				if(a[i]==a[r]){
					ans+=a[i];
					a[r]=0;a[i]=0;
					r--;
					i++;
					continue;
				}
				else{
					ans+=a[r];
					a[i]-=a[r];
					a[r]=0;
					r--;
					continue;
				}
			}
		}
	}
	cout<<ans;
} 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int te=1;
//	cin>>te;
	while(te--){
		solve();
	}
	return 0;
}
