#include<bits/stdc++.h>
using namespace std;
const int INF=107341823;
int n,m,a[100005],rx[100005],D;
void ru(int &a){
	a=0;char in=getchar();bool zf=0;
	while(in<'0'||in>'9'){if(in=='-')zf=1;in=getchar();}
	while(in>='0'&&in<='9'){a=(a<<1)+(a<<3)+(in^48);in=getchar();}
	if(zf)a=-a;
}
void S(int sy,int I,int sum){
	if(sy==0){D=max(D,sum);return;}
	if(sum<D)return;
	for(int i=I+1;i<=n-sy;i++)
	S(sy-1,i,sum&a[i]);
}
bool cmp(int a,int b){
return a>b;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ru(n);ru(m);
	for(int i=1;i<=n;i++)ru(a[i]);
	if(n<=2000){
		S(m,0,INF);
		cout<<D;
	}
	else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
}