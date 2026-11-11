#include<iostream>

using namespace std;
constexpr int N=2e5+5;
bool Beg;

string c1,c2,s1,s2;
int a1,a2;
char b1,b2;

bool End;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000\n",exit(0);
	a1=s1[0]*128+s1[1],b1=s1[2];
	a2=s2[0]*128+s2[1],b2=s2[2];
	if(a1!=a2)cout<<"1000\n",exit(0);
	if(b1>b2)swap(b1,b2);
	if(b1<'D'&&'C'<b2)cout<<"1100\n",exit(0);
	if(b1=='A'&&b2=='C')cout<<"1110\n",exit(0);
	cout<<"1111\n";
	cerr<<(&Beg-&End)/1024.0/1024.0<<" MB\n";
	return 0;
}
