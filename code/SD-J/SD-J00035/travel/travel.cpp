#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=100010;
string c1,s1,c2,s2;
bool ans[5];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans[1]=1;
	if(ans[1]&&s1[0]==s2[0]&&s1[1]==s2[1]) ans[2]=1;
	if(ans[2]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))) ans[3]=1;
	if(ans[3]&&abs(s1[2]-s2[2])==1) ans[4]=1;
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	return 0;
}
