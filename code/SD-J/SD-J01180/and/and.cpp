#include <bits/stdc++.h>
#define int long long
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define Auto(v,a) for(auto v:a)
#define ps() putchar(' ')
#define pe() putchar('\n')
using namespace std;
const int N=2e5+10;
int a[N];
void read(int &x){
	int a=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar()){
		if(c=='-'){
			f=-1;
		}
	}
	for(;isdigit(c);c=getchar()){
		a=a*10+c-48;
	}
	x=a*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0;
	read(n),read(m);
	rep(i,1,n){
		read(a[i]);
	}
	sort(a+1,a+1+n,cmp);
	maxn=a[1];
	rep(i,2,m){
		int test=maxn&a[i];
		if(test!=0){
			maxn&=a[i];
		}
		else{
			m++;
			i++;
		}
	}
	write(maxn);
	return 0;
}


