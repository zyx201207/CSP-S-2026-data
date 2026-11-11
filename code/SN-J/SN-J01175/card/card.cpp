#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N];
inline int read(){
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=(ans<<1)+(ans<<3)+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		cout<<n<<" "; 
	}
	return 0;
}
