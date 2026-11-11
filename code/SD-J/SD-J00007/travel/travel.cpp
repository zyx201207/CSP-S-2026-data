#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define se second
#define fi first
using namespace std;
const int N=1e5+5;
ll c1,s1,c2,s2;
char p,q;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>p>>c2>>s2>>q;
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else{
		cout<<1;
		if(s1!=s2) cout<<"000";
		else{
			cout<<1;
			if(p>'C'&&q>'C') cout<<"11";
			else if(p<='C'&&q<='C'){
				cout<<1;
				if(p=='B'||q=='B') cout<<1;
				else cout<<0;
			}
			else{
				cout<<"00"; 
			}
		}
	}
	return 0; 
}
