#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
char c[N];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		x+=a[i];
	}
	int sum=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[sum++]=c[i];
		}
	}
	int y=x,ans=0;
	if(x%2==1) x=x/2+1;
	else x=x/2;
	for(int i=1,j=y;i<=x,j>=x;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}
