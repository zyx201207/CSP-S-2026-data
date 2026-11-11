#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],ans,n;
char s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1,j=n;i<=j;){
		if(a[i]<=a[j]){
			if(s[i]!=s[j]) ans+=a[i];
			a[j]-=a[i];
			a[i]=0;
			i++;
		}
		else {
			if(s[i]!=s[j]) ans+=a[j];
			a[i]-=a[j];
			a[j]=0;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
