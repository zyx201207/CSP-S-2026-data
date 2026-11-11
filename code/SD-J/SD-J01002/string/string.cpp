#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
int n,m,a[N],ans,idx;
char s[N],t[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int maxx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx*n<=1e7){
		for(int i=1;i<=n;i++){
			while(a[i]--){
				t[++idx]=s[i];
			}
		}
		for(int i=1,j=idx;i<=j;i++,j--){
			ans+=(t[i]!=t[j]);
		}
		cout<<ans;
		return 0;
	}
	int t=0,k=0;
	for(int i=1,j=n;i<=j;i++,j--){
		if(s[i]!=s[j]){
			if(a[i]==a[j]){
				ans+=a[i];
			}
			else{
				ans+=min(a[i],a[j]);
				if(a[i]<a[j]){
					a[j]-=a[i];
					j++;
				}
				else{
					a[i]-=a[j];
					i--;
				}
			}
		}
		else if(a[i]!=a[j]){
			if(a[i]<a[j]){
				a[j]-=a[i];
				j++;
			}
			else{
				a[i]-=a[j];
				i--;
			}
		}
	}
	cout<<ans;
	return 0;
}
