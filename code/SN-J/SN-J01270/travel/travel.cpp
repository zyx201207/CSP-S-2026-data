//Red question,and it runs for O(1) ,costs memory less than 1KB
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c1,c2;
string s1,s2;
ll p1,p2;
ll t1,t2;
bool f;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1=(s1[0]-'0')*10+s1[1]-'0';
	p2=(s2[0]-'0')*10+s2[1]-'0';
	t1=s1[2]-'A';
	t2=s2[2]-'A';
	f=false;
	cout<<((f=(c1==c2))?1:0);
	cout<<((f=(f&&p1==p2))?1:0);
	cout<<((f=(f&&((t1<=2&&t2<=2)||(t1>=3&&t2>=3))))?1:0);
	cout<<((f=(f&&abs(t1-t2)==1))?1:0);
	return 0;
} 
