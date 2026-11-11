#include <bits/stdc++.h>
#define int long long
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define Auto(v,a) for(auto v:a)
#define ps() putchar(' ')
#define pe() putchar('\n')
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],ans[M];
bool b[N];
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
int find(int a[],int s,int e,int x){
	rep(i,s,e){
		if(a[i]==x){
			return i;
		}
	}
	return -1;
}
signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	read(n),read(m);
	rep(i,1,n){
		read(a[i]);
	}
	rep(i,1,n){
		rep(j,1,n){
			b[j]=false;
		}
		rep(j,i,n){
			if(find(a,i,n,a[j])!=-1){
				rep(k,j+1,n){
					b[k]=1;
				}
			}
		}
		rep(j,i,n){
			if(b[j]==false){
				ans[j]++;
			}
		}
	}
	rep(i,1,m){
		write(ans[i]);
		ps();
	}
	return 0;
}


