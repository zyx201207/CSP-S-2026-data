#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

inline long long read(){
	short f=1;long long ret=0;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		ret=(ret<<3)+(ret<<1)+(ch-48);
		ch=getchar();
	}
	return ret*f;
}
bool cmp(int a,int b){
	return a>b;
}
long long a[500500];//shuju
long long qz[500500];//qianzhuihe
int n;
long long m;
long long ma=0;
void refresh(long long x){
	ma=max(ma,x);
}
long long need(int l,int r){//o1
	return (long long)a[l]*(r-l+1)-qz[r]+qz[l-1];
}
//todo erfeng
//ef1check
bool check(int l,int x){
	return m>=need(l,x);
}
//ef2 erf
//log
void logn(string warn,long long *t,int tl){
	cerr<<"log list:"<<"in "+warn+".\n";
	for(int i=1;i<tl;i++){
		cerr<<t[i]<<' ';
	}cerr<<"End.\n";
}
void log1(string warn,int x){
	cerr<<"log: "+warn+" "<<x<<".\n";
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	qz[0]=0;
	for(int i=1;i<=n;i++){//n
		a[i]=read();
	}
	sort(a+1,a+n+1,cmp);//nlogn
	for(int i=1;i<=n;i++){//n
		qz[i]=qz[i-1]+a[i];
	}
	//logn("data",a,n);
	//logn("qianzhui",qz,n);
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			
			int mid=r+(l-r)/2;
			if(check(i,mid)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		refresh(r-i+1);
	}
	printf("%d\n",ma);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//T1 1552 1-4 right pts>=90 X X XXX //freopen("crystal.in","r",stdin);


