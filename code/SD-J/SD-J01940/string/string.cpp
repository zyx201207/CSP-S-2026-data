#include<bits/stdc++.h>
#define int long long
using namespace std;
struct S{
	int a;
	char c;
}s[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	int as=0;
	int l=1,r=n;
	while(l<r){
		int j=min(s[l].a,s[r].a);
		if(s[l].c!=s[r].c) as+=j;
		s[l].a-=j;
		s[r].a-=j;
		if(s[l].a==0) l++;
		if(s[r].a==0) r--;
	}
	cout<<as;
	return 0;
}

