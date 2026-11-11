#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,a[N],ans,m;
char c[N];
string s;
signed main(){
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-i-1]){
			ans++;
		}
	} 
	cout<<ans;
	return 0;
} 

