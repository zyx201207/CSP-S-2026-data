#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,l;
string ch[200005];
string s;
void add(string tmp,int x){
	for(;x;x>>=1){
		if(x&1)s=s+tmp;
		tmp=tmp+tmp;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>ch[i],add(ch[i],a[i]);
	l=s.size();
	for(int i=0;i<l/2;i++)if(s[l-1-i]!=s[i])ans++;
	cout<<ans;
	return 0;
}
