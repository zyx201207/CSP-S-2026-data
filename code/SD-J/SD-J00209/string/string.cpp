#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
LL n,a,q,s[N];
char c;
string qwe=" ";
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a>>c;
		LL t=a;
		while(t--) 
			qwe+=c;
	}
	LL len=qwe.size()-1,ans=0;
	if(len%2==0) {
		LL l=(len/2)-1,r=(len/2)+2;
		while(l>=1&&r<=len) {
			if(qwe[l]!=qwe[r])
				ans++;
			l++;
			r++;
		}
	}else {
		LL l=len/2,r=(len/2)+2;
		while(l>=1&&r<=len) {
			if(qwe[l]!=qwe[r])
				ans++;
			l++;
			r++;
		}
	}
	cout <<ans;
	return 0;
}

