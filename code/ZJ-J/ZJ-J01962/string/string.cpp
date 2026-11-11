#include<bits/stdc++.h>
using namespace std;
const int mxn=2e5+5;
long long ll,rl,cnt;
int n,a[mxn],l,r;
char s[mxn];
int main(){
	//Trick||Treat!
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;r=n+1;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	l=1;ll=a[l];
	while(l<r-1){
		int x;
		if(ll<=rl){
			ll+=a[++l];
			if(ll<=rl) x=a[l];
			else x=rl+a[l]-ll;
		}
		else{
			rl+=a[--r];
			if(ll>=rl) x=a[r];
			else x=ll+a[r]-rl;
		}
		if(s[l]!=s[r]) cnt+=x;
	}
	cout<<cnt;
	return 0;
}
