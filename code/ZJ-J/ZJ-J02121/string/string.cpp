#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,r=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
	}
	int l=0,i=0,cnt=n,ans=0;
	while(l<=r/2){
		i++;
		if(l+a[i]<=r/2){
			l+=a[i];
			while(a[i]>=a[cnt]&&i<cnt){
				if(c[i]!=c[cnt])
					ans+=a[cnt];
				a[i]-=a[cnt];
				cnt--;
			}
			if(a[i]>0&&a[i]<a[cnt]){
				if(c[i]!=c[cnt])
					ans+=a[i];
				a[cnt]-=a[i];
			}
		}
		else{
			if(c[i]!=c[cnt])
				ans+=a[cnt];
			break;
		}
	}
	cout<<ans;
	return 0;
}
