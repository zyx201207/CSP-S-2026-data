#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b)for(int i = a;i<=b;i++)
#define f_(i,a,b)for(int i = a;i>=b;i--)
const int N = 2e5+10;
int ar[N][35],br[N],js,cr[N];
string s[N];
int maxs,n,m;
long long ans = 0;
void solve(){
	f(i,1,N){
		br[i] = 1;
	}
	int num = maxs;
	f_(i,maxs,1){
		js = 0;
		num--;
		f(j,1,n){
			cr[j] = br[j];
		}
		f(j,1,n){
			if(ar[j][i]!=1){
				br[j] = 0;
				continue;
			}
			if(br[j] == 1){
				js++;
			}
		}
		if(js>=m){
			ans+=pow(2,num);
		}else{
			f(j,1,n){
				br[j] = cr[j];
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	f(i,1,n){
		int a;
		cin>>a;
		int dir = 0;
		while(a){
			int g = a%2;
			a/=2;
			ar[i][++dir]  = g;
		}
		maxs = max(maxs,dir);
	}
	solve();
	cout<<ans;
}
