#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
struct node{
	int a;
	char c;
}q[N];
string s;
int ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].c;
		for(int j=1;j<=q[i].a;j++){
			s+=q[i].c;
		}
	}
//	cout<<s<<"\n";
	int sz=s.size();
	s=' '+s;
	for(int i=1;i<=(sz>>1);i++){
		if(s[i]!=s[sz-i+1]){
//			cout<<s[i]<<" "<<s[sz-i+1]<<"\n";
			++ans;
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
/*
2
2 a
3 a

9:19 ´òÍê±©Á¦
 
*/

