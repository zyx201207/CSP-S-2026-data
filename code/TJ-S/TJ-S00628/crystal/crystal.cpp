#include<iostream>
#include<cstdlib>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
using namespace std;
namespace KitoTaisu{
	char *p1,*p2,buf[32769];
	#define nc() ((p1==p2&&(p2=((p1=buf)+fread(buf,1,32767,stdin)),p1==p2))?EOF:(*p1++))
	template<typename ra>
	ra read(){
		ra x=0,f=1;
		char ch=nc();
		while(ch<48||ch>57){
			if(ch=='-')f=-1;
			ch=nc();
		}
		while(47<ch&&ch<58){
			x=(x<<3)+(x<<1)+(ch^48);
			ch=nc();
		}
		return x*f;
	}
	int readstr(char* str,char l='a',char r='z'){
		int len=0;
		char ch=nc();
		while(ch<l||ch>r){
			ch=nc();
		}
		while(l<=ch&&ch<=r){
			str[len++]=ch;
			ch=nc();
		}
		return len;
	}
	char readchar(char l='a',char r='z'){
		char ch=nc();
		while(ch<l||ch>r){
			ch=nc();
		}
		return ch;
	}
}
using KitoTaisu::read;
using KitoTaisu::readstr;
using KitoTaisu::readchar;
int n,len,ans;
long long m,sum,a[500002];
queue<long long> qu;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read<int>(),m=read<long long>();
	for(int i=1;i<=n;++i)a[i]=read<long long>();
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;++i){
		sum+=len*(a[i]-a[i-1]);
		qu.push(a[i]),++len;
		while(sum>m){
			sum-=(a[i]-qu.front());
			qu.pop();
			--len;
		}
		ans=max(ans,len);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
