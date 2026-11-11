#include <bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
struct node{
	long long a;
	char c;
}s[200010];
long long l,r,la,ra;
char lc,rc;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	l=1,r=n;
	la=s[l].a,lc=s[l].c,ra=s[r].a,rc=s[r].c;
	while(l<r){
		if(la>=ra){
			if(lc!=rc){
				ans+=ra;
			}
			la-=ra;
			ra=0;
		}
		else{
			if(lc!=rc){
				ans+=la;
			}
			ra-=la;
			la=0;
		}
		if(la==0){
			l++;
			la=s[l].a,lc=s[l].c;
		}
		if(ra==0){
			r--;
			ra=s[r].a,rc=s[r].c;
		}
	}
	cout<<ans;
	return 0;
}