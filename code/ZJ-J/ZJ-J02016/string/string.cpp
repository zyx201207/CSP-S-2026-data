#include<bits/stdc++.h>
#define int long long
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int n;
long long a[200100];
char c[200100];
long long s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		scanf("%c",&c[i]);
	}
	int l=1,r=n;
	long long l1=a[l],r1=a[r];
	while(l<=n&&r>=1){
		long long x=min(l1,r1);
		if(c[l]!=c[r]){
			s+=x;
		}
		l1-=x;
		r1-=x;
		if(l1==0){
			l++;
			l1=a[l];
		}
		if(r1==0){
			r--;
			r1=a[r];
		}
	}
	cout<<s/2;
	return 0;
}
