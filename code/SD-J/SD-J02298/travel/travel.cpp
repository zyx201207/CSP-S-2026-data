#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace FastIo{template<typename T>void read(T &x){int f=1;char ch=getchar();x=0;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}x=x*f;}template<typename T1,typename ...T2>void read(T1 &x1,T2 &...x2){read(x1);read(x2...);}}using namespace FastIo;

const int N=1e5+5;
string a1,a2,b1,b2;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)cout<<"1";
	else{cout<<"0000";return 0;}
	if(a2[0]==b2[0]&&a2[1]==b2[1])cout<<"1";
	else{cout<<"000";return 0;}
	if(((a2[2]>='A'&&a2[2]<='C')&&(b2[2]>='A'&&b2[2]<='C'))||((a2[2]>='D'&&a2[2]<='F')&&(b2[2]>='D'&&b2[2]<='F')))cout<<"1";
	else{cout<<"00";return 0;}
	if((a2[2]=='A'&&b2[2]=='C')||(a2[2]=='C'&&b2[2]=='A'))cout<<"0";
	else cout<<"1";
}
