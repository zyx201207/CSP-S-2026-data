#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,m;
int a[maxn];
bool b[35][maxn];
long long p[40];
bool can[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		can[i]=1;
	}
	p[1]=1;
	for(int i=2;i<=32;i++){
		p[i]=p[i-1]*2ll;
	}
	int maxc=0;
	for(int i=1;i<=n;i++){
		int x=a[i];
		int cnt=0;
		while(x){
			b[++cnt][i]=x&1;
			x>>=1;
		}
		maxc=max(maxc,cnt);
	}
	long long ans=0;
	for(int i=maxc;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(b[i][j]){
				if(can[j])cnt++;
			}
		}
		if(cnt>=m){
			ans+=p[i];
			for(int j=1;j<=n;j++){
				if(!b[i][j])can[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
