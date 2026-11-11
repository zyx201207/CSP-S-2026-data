#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
int n;
long long a[N];
char s[N];
long long l;
long long r;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		l+=a[i];
	}
	r=n;
	l/=2;
	for(int i=1;i<=n;i++){
		l-=a[i];
		while(a[i]-a[r]>=0&&r>i){
			a[i]-=a[r];
			ans+=a[r]*(s[i]!=s[r]);
			r--;
		}
		ans+=a[i]*(s[i]!=s[r]);
		a[r]-=a[i];
		if(l<=0)break;
	}
	cout<<ans;
	return 0;
}
