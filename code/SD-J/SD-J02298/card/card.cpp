#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace FastIo{template<typename T>void read(T &x){int f=1;char ch=getchar();x=0;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}x=x*f;}template<typename T1,typename ...T2>void read(T1 &x1,T2 &...x2){read(x1);read(x2...);}}using namespace FastIo;

const int N=1e5+5;
int n,m;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	read(n,m);
	for(int i=1;i<=m;i++)cout<<0<<" ";
}

