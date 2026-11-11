#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,l,cnt;
int a[N];
char c[N];
char s[N],s1[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i],l+=a[i];
		for(int j=l-a[i]+1;j<=l+a[i];j++)s[j]=c[i];
	}
	for(int i=l/2,j=1;i>=1;i--,j++){
		s1[j]=s[i];
	}
	if(l%2==0){
		for(int i=l/2+1,j=1;i<=l;i++,j++){
			if(s[i]!=s1[j])cnt++;
		}
	}
	else
		for(int i=l/2+2,j=1;i<=l;i++,j++){
			if(s[i]!=s1[j])cnt++;
		}
	cout<<cnt;
	return 0;
}
