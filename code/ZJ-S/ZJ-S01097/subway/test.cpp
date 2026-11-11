#include<bits/stdc++.h>
#include<windows.h>
#define fst first
#define scd second
#define db double
#define ll long long
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define sz(x) ((int)x.size())
#define ms(f,x) memset(f,x,sizeof(f))
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)
#define ACN(i,H_u) for(int i=H_u;i;i=E[i].nxt)
using namespace std;
//char buf[1<<20],*p1=buf,*p2=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
template<typename T>void rd(T&x){
	x=0;bool f=false;char ch=getchar();
	while(ch<48||ch>57)f|=ch==45,ch=getchar();
	while(ch>=48&&ch<=57)x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
template<typename T,typename...Args>
void rd(T&x,Args&...y){rd(x),rd(y...);}
//dfs

//wmr

//incra

//lottle
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	char name[16];sprintf(name,"subway");
	int n=7;
	L(i,1,n){
		char sys[128];
		sprintf(sys,"copy %s%d.in %s.in\n",name,i,name);
		system(sys);
		sprintf(sys,"%s.exe\n",name);
		system(sys);
		sprintf(sys,"fc %s.out %s%d.ans\n",name,name,i);
		system(sys);
	}
	return 0;
}

