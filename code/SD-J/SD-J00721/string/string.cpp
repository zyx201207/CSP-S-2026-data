#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct node{
	int x;
	char ch;
}s[N];
int n,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>s[i].x>>s[i].ch;
	int i=1,j=n;
	while(i<=j&&s[i].x>0&&s[j].x>0){
		if(s[i].ch!=s[j].ch) ans+=min(s[i].x,s[j].x);
		if(s[i].x>s[j].x) s[i].x-=s[j].x,j--;
		else if(s[i].x<s[j].x) s[j].x-=s[i].x,i++;
		else i++,j--;
	}
	cout<<ans;
	return 0;
}

