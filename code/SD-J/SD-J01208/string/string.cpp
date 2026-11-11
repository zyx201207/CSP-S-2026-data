#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
const int inf = 2e9;

long long n,en;
struct q{
	long long len,l,r;
	char c;
}a[N];
//string s="";
int read(){
	int y = 1,x = 0;
	char c = getchar();
	while(c>'9'||c<'0'){
		if(c=='-') y = -1;
		c = getchar();
	}
	while(c>='0'&&c<='9'){
		x = x*10+(c-'0');
		c = getchar();
	}
	return x*y;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		a[i].len = x;
		a[i].c = c;
		a[i].l = en+1;
		a[i].r = en+x;
//		cout<<a[i].r<<" ";
		en+=x;
	}
	long long l1 = 1,r1 = en,l2 = 1,r2 = n,ans = 0;
	while(l1<r1){
		long long t = min(a[l2].r-l1+1,a[r2].len-(a[r2].r-r1));
//		cout<<t<<" "<<l1<<" "<<r1<<'\n';
		if(a[l2].c!=a[r2].c) ans+=t;
		l1 = l1+t ,r1 = r1-t;
		while(l1>=a[l2+1].l) l2++;
		while(r1<=a[r2-1].r) r2--;
	}
	cout<<ans;
	return 0;
} 
