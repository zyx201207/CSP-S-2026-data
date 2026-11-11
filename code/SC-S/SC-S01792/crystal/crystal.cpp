#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+7;

int n,m,ans;
int val[maxn],pre[maxn];

int in(){
	int t=0,k=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		t=(t<<3)+(t<<1)+(c^48);
		c=getchar();
	}
	return k*t;
}

void out(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x^48);
	else out(x/10),putchar(x%10^48);
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=in(),m=in();
	for(int i=1;i<=n;i++){
		val[i]=in();
//		pre[i]=pre[i-1]+val[i];
	}
	sort(val+1,val+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+val[i];
	}
	for(int l=1,r=1;r<=n;r++){
		while(l<r&&pre[r]-pre[l-1]+m<val[r]*(r-l+1)) l++;
		ans=max(ans,r-l+1);
	}
	out(ans);
	return 0;
} 