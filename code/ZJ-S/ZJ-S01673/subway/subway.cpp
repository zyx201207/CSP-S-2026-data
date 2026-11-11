#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
using namespace std;
const int N=5e5+10;
inline int read(){
	int f=1,s=0;
	char c=getchar();
	while(!(c>='0'&&c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+(c-'0');
		c=getchar();
	}
	return f*s;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	string s="";
	while(x){
		s+=(x%10)+'0';
		x/=10;
	}
	if(s==""){
		putchar('0');
	}
	per(i,s.size()-1,0){
		putchar(s[i]);
	}
}
int w[N];
map<int,map<int,int> >mp;
int a[N],t[N];
void solve(){
	int c=read(),n=read(),m=read(),d=read(),q=read();
	rep(i,1,m){
		w[i]=read();
	}
	rep(i,1,m){
		rep(j,1,m){
			mp[i][j]=0x3f3f3f3f;
		}
		mp[i][i]=0;
	}
	rep(i,1,n){
		int k=read();
		rep(j,1,k){
			a[j]=read();
			t[j]=read();
		}
		rep(j,1,k){
			rep(x,1,k){
				if(j==x){
					continue;
				}
				int aaa=t[j]+t[x];
				mp[a[j]][a[x]]=mp[a[x]][a[j]]=min(mp[a[j]][a[x]],aaa);
			}
		}
	}
	rep(k,1,m){
		rep(i,1,m){
			rep(j,1,m){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]+w[k]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		write(mp[x][y]+w[x]+w[y]);
		putchar('\n');
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _=1;
//	_=read();
	while(_--){
		solve();
	}
	return 0;
}
