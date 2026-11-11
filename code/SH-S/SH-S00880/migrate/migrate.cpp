#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;


const int N=2e6+10;
const int N2=5e3+10;
int c,T,n;
ll d;

ll read(){
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

void write(ll x){
	if(x<0) putchar('-');
	else if(x<10) putchar(x+'0');
	else write(x/10), putchar(x%10+'0');
}

namespace BF{
	int ans[N2][N2];
	ll x[N2],cnt;
	vector<int> pos;
	
	void solve(int l,int r){
		if(x[pos[0]] - x[l] > d) return;
		for(int i=1;i<(int)pos.size();i++) if(x[pos[i]] - x[pos[i-1]] > d) return;
		if(x[r] - x[pos[(int)pos.size()-1]] > d) return;
		ans[l][r]++;
	}
	
	void dfs(int loc,int r,int aim,int nl,int nr){
		if(aim==0){
			solve(nl,nr);
			return;
		} 
		
		for(int i=loc;i<=r;i++){
			pos.push_back(i);
			dfs(i+1, r, aim-1, nl, nr);
			pos.pop_back();
		}
	}
	
	void main(){
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		cnt=0;
		pos.clear();
		for(int len=3;len<n;len++)
		for(int l=1;l+len<=n;l++){
			int r=l+len, num=1;
			ans[l][r] = 0;
			while(!ans[l][r]){
				ans[l][r] = 0;
				dfs(l+1,r-1,num,l,r);
				num++;
				if(ans[l][r]==2){
					cnt++;
				} 
				if(num>3) break;
			}
		}
		write(cnt), putchar('\n');
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	c=read(), T=read();
	while(T--){
		n=read(), d=read();
		if(n<=5000) BF::main();
	}
	
	return 0;
}
