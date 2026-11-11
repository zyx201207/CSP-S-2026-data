#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],b[N];
int ans=0;
inline int input(){
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') w=-w;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*w;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=input(),m=input();
	for(int i=1;i<=n;i++) a[i]=input();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=a[i]+b[i-1];
	for(int i=1,j=1;i<=n;){
		while(j<=n&&(j-i+1)*a[j]<=b[j]-b[i-1]+m) j++;
		ans=max(ans,j-i);
		if(j==n) break;
		i++;
	}
	cout<<ans;
	return 0;
}
