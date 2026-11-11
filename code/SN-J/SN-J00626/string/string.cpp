//胡海瑧 西安市铁一中学 SN-J00626 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=2e5+5;
int a[N],len,ans=0;
char c[N];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){cout<<0;return 0;}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	if(len&1){
		for(int i=0;i<=(len-3)/2;i++){
			if(s[i]!=s[len-i-1]) ans++;
		}
	}
	else{
		for(int i=0;i<=(len-2)/2;i++){
			if(s[i]!=s[len-1-i]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
