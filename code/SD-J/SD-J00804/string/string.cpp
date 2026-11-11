#include <bits/stdc++.h>
using namespace std;
#define N 200000
#define int long long
int n,a[N+10],len;
char ch[N+10];
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    s=" ";
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>ch[i];
		len+=a[i];
		for(int j=1;j<=a[i];++j)s+=ch[i]; 
	}
	int cnt=0;
	if(len&1){
		for(int l=((len+1)>>1),r=((len+1)>>1);l>=1&&r<=len;--l,++r){
			if(s[l]!=s[r])++cnt;
		}
	}else{
		for(int l=(len>>1),r=l+1;l>=1&&r<=len;--l,++r){
			if(s[l]!=s[r])++cnt;
		}
	}
	cout<<cnt;
	return 0;
}
