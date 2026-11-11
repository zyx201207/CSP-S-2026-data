#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int ret=0;bool opt=0;char in=getchar();
	while(!isdigit(in)){opt|=(in=='-');in=getchar();}
	while(isdigit(in)){ret=ret*10+(in^48);in=getchar();}
	return (opt?-ret:ret);
}
int lent,knum,ret;
int itms[500010];
int sumt[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	lent=read();knum=read();
	for(int i=1;i<=lent;i+=1){
		itms[i]=read();
	}sort(itms+1,itms+lent+1);
	for(int i=1;i<=lent;i+=1){
		sumt[i]=sumt[i-1]+itms[i];
	}for(int i=1;i<=lent;i+=1){
		int l=1,r=i,p=1;
		while(l<=r){
			int mid=(r-l)/2+l;
			int v=sumt[i]-sumt[mid-1];
			int m=itms[i]*(i-mid+1)-v;
			if(m>knum)l=mid+1;
			else r=mid-1,p=i-mid+1;
		}ret=max(ret,p);
	}printf("%lld\n",ret);
	return 0;
}