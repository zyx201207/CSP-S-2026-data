#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1114514];
int cnt=0;
char s[1114514];
int _=0;
int ans=0;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>s[i];
		cnt+=a[i];

	}
	int L=1;
	int R=n;
	while(1){
		if(L>=R){
			cout<<ans;
			return 0;
		}
		if(s[L]!=s[R]){
			ans+=min(a[L],a[R]);
			if(a[L]>a[R]){
				
				a[L]-=a[R];
				R--;
			}else if(a[L]<a[R]){
				
				a[R]-=a[L];	
				L++;
			}else{
				L++;
				R--;
			}
		}else{
			if(a[L]>a[R]){
				
				a[L]-=a[R];
				R--;
			}else if(a[L]<a[R]){
				
				a[R]-=a[L];	
				L++;
			}else{
				L++;
				R--;
			}			
		}
		
	}
	return 0;
}
