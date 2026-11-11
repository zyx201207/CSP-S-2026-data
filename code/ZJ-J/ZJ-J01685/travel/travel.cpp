#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end() 
#define fr(x) freopen(#x".in","r",stdin)
#define fw(x) freopen(#x".out","w",stdout) 
using namespace std;
using db=double;
using ll=long long;
using ull=unsigned long long;
using PI=pair<int,int>;
const int N=2e5+5;
string s1,s2,c1,c2;
int main()
{
	fr(travel);
	fw(travel);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2) 
	{
		if(c1>c2) swap(c1,c2);
		if(c1[0]==c2[0]&&c1[1]==c2[1]) 
		{
			if(c1[2]>='A'&&c1[2]<='C'&&c2[2]>='A'&&c2[2]<='C'||c1[2]>='D'&&c1[2]<='F'&&c2[2]>='D'&&c2[2]<='F')
			{
				if((int)c2[2]-c1[2]==1) cout<<"1111\n";
				else cout<<"1110\n";
			}
			else cout<<"1100\n";
		}
		else cout<<"1000\n";
	}
	else cout<<"0000\n";
	return 0;
}