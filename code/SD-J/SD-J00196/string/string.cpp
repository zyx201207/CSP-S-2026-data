#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e8;
void fc(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
int n,ans;
string s;
signed main(){
	fc();
	cin>>n;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		while(a--) s+=c;
	}
	int len=s.size();
	for(int i=0;i<len/2;i++){
		int j=len-i-1;
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
