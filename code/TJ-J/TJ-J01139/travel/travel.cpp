#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
int t=1;
string c1,c2,s1,s2; 
bool f1,f2,f3,f4;
void solve()
{
	cin>>c1>>s1>>c2>>s2;
	f1=c1==c2;
	f2=s1[0]==s2[0]&&s1[1]==s2[1];
	f3=(s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C');
	f4=(s1[2]<='C'&&s2[2]<='C'&&(s1[2]=='B'||s2[2]=='B'))
		||(s1[2]>'C'&&s2[2]>'C');
	cout<<f1<<(f1&&f2)<<(f1&&f2&&f3)<<(f1&&f2&&f3&&f4)<<'\n';
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}

