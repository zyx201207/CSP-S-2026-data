#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans,last,start,sum,cnt;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		cnt+=a[i];
		start++;
		if(cnt>sum/2){
			break;
		}
	}
	last=n;
	for(int i=1;i<=start;i++){
		int len=a[i];
		while(len>=a[last]){
			if(c[last]!=c[i]){
				ans+=a[last];
			}
			len-=a[last];
			a[last]=0;
			last--;
		}
		if(c[last]!=c[i]){
			ans+=len;
		}
		a[last]-=len;
	}
	cout<<ans;
	return 0;
}

