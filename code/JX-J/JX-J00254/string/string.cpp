#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll a[N];
char c[N];
ll mid,n,cnt,js,gcd;
string s;

signed main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        gcd=__gcd(gcd,a[i]);
	}
	for(int i=1;i<=n;i++){
        a[i]/=gcd;
        mid+=a[i]/2;
        js+=a[i]%2;
	}

	mid+=js/2;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
	}
	string s1=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<mid;i++){
        cnt+=(s[i]!=s1[i]);
	}
	cout<<cnt*gcd;
	return 0;
}
