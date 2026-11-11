#include<bits/stdc++.h>
#define lonit long long
using namespace std;
const int MAXN=5e5+5;
lonit n,m;
lonit a[MAXN],f[MAXN],f2[MAXN],mmax=-1e16;
bool cmp(int x,int y){return x<y;}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	lonit tot=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+(i-tot)*(a[i]-a[i-1]);
		f2[i]=f2[i-1]+1;
		if(m<f[i]){
			while(m<f[i]){
				f[i]-=a[i]-a[tot++];
				f2[i]--;
			}
		}
	}
	for(int i=1;i<=n;i++) mmax=max(mmax,f2[i]);
	cout<<mmax;
	return 0;
}
