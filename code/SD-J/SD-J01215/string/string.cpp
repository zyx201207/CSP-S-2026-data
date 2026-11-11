#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int x;
	char c;
}a[200005];
string s="#";
int n,cnt,l,gcd;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		if(i==1){
			gcd=a[i].x;
		}
		else{
			gcd=__gcd(gcd,a[i].x);
		}
	}
	for(int i=1;i<=n;i++){
		a[i].x/=gcd;
		l+=a[i].x;
		for(int j=1;j<=a[i].x;j++){
			s+=a[i].c;
		}
	}
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]){
			cnt+=gcd;
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
