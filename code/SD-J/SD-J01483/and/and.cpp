#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,INF=(1<<31)-1;
int a[N],f[N];
int cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=2e4+5){
		sort(a+1,a+n+1,cmp);
		int res=a[1],cnt=0;
		for(int i=1;i<=n;i++){
			res=(res&a[i]);
			cnt++;
			if(cnt==m){
				cout<<res;
				return 0;
			}
		}
	}
	//for(int i=1;i<=m;i++)f[i]=INF;
	//sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		f[0]=a[i];
		for(int j=min(i,m);j>=1;j--){
			//if(f[j]==INF)f[j]=a[i];
			f[j]=max(f[j],f[j-1]&a[i]);
		}
	}
	cout<<f[m];
	return 0;
} 

