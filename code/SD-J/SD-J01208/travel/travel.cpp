#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
const int inf = 2e9;

string c1,s1,c2,s2;
bool f1,f2,f3,f4;
int read(){
	int y = 1,x = 0;
	char c = getchar();
	while(c>'9'||c<'0'){
		if(c=='-') y = -1;
		c = getchar();
	}
	while(c>='0'&&c<='9'){
		x = x*10+(c-'0');
		c = getchar();
	}
	return x*y;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) f1 = 1;
	if(f1&&s1[0]==s2[0]&&s1[1]==s2[1]) f2 = 1;
	if(f2&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')) f3 = 1;
	if(f3&&(s1[2]!='A'||s2[2]!='C')&&(s2[2]!='A'||s1[2]!='C')) f4 = 1;
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
