#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N=5e5+10;
ll n,m,a[N],sa[N];
int ans=0;

ll r(){
	ll k=0; int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
} 

void w(ll x){
	if(x<0) putchar('-');
	else if(x<10) putchar(x+'0');
	else w(x/10), putchar(x%10+'0');
}

bool judge(int l,int r){
	ll t=a[r]*(r-l+1) - (sa[r]-sa[l-1]); //²Ù×÷´ÎÊý
	return t<=m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	n=r(), m=r();
	for(int i=1;i<=n;i++) a[i]=r();
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++){
		if(i==1) sa[i] = a[i];
		else sa[i] = sa[i-1] + a[i];
	} 
	
	for(int r=1;r<=n;r++){
		int nl=0, nr=r+1, mid=0;
		while(nl+1<nr){
			mid=(nl+nr)/2;
			if(judge(mid, r)){
				nr=mid;
			} 
			else{
				nl=mid;
			}
		}
		ans = max(ans, r - nr + 1);
	}
	w(ans);
	return 0;
}

