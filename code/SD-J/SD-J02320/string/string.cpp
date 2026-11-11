#include<bits/stdc++.h>//string
using namespace std;
struct node{
	int a;
	char c;
}s[200005];
long long l,r,lx,rx,n,ans;
char lc,rc;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	l=1,r=n;
	while(l<r){
		lx=s[l].a;
		rx=s[r].a;
		lc=s[l].c;
		rc=s[r].c;
		if(lx<rx){
			l++;
			s[r].a-=lx;
		}else if(lx>rx){
			r--;
			s[l].a-=rx;
		}else{
			l++,r--;
		}
		if(lc!=rc) ans+=min(lx,rx);
	}
	cout<<ans;
	return 0;
}
