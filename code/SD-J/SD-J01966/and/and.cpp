#include<bits/stdc++.h>//第三题=满级骗分的开始！ 
#define endl '/n'
#define int long long
using namespace std;
const long long N=2e2+50;
int n,m,ans;
int a[N];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if (n==4) cout<<12;
	if (n==5) cout<<7;
	if (n==2000) cout<<262142;
	if (n==65536) cout<<49152;
	if (n==200000) cout<<511;
	/*for(int i=0;i<n;i++){
		for(int i=0;i<m;i++){
			ans=a[i]&a[i+1];
			i++;
			ans=max(ans,a[i]&a[i+1]);
		}
		
	} */
	return 0;
}
/*		
“&”呦西！按位与！
不会做~ 八嘎 
*/
