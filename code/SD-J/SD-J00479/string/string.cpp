#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,i,j;
ll res;
struct Part{
	int len;
	char c;
}a[N];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		a[i].len=read();
		a[i].c=getchar();
	}
	i=1,j=n;
	while(i<j){
		if(a[i].c==a[j].c){
			if(a[i].len<a[j].len){
				a[j].len-=a[i].len;
				++i;
			}	
			else if(a[i].len==a[j].len){
				++i;
				--j;
			}
			else{
				a[i].len-=a[j].len;
				--j;
			}
		}
		else{
			if(a[i].len<a[j].len){
				res=res+(ll)a[i].len;
				a[j].len-=a[i].len;
				++i;
			}
			else if(a[i].len==a[j].len){
				res=res+(ll)a[i].len;
				++i,--j;
			}
			else{
				res=res+(ll)a[j].len;
				a[i].len-=a[j].len;
				--j;
			}
		}
	}
	printf("%lld",res);
	return 0;
}
