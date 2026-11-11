#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 200005
string s;
int ans,len;
struct node{
	char c;
	int cnt;
}a[N]; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		int cnt;
		cin>>cnt>>c;
		s.append(cnt,c);
		len+=cnt;
	}
    s=' '+s;
    for(int i=1;i<=len/2;i++){
    	ans=ans+(s[i]!=s[len-i+1]);
	}
	cout<<ans;
	return 0;
}

