#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++)
			if(a[i]>maxn) maxn=a[i];
		cout<<maxn;
		return 0;
	}
	else if(m==2){
		int maxn=0;
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>maxn) maxn=(a[i]&a[j]);
			}
		}
		
		cout<<maxn;
		return 0;
	}
	else if(n==m){
		int cnt=0;
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--)
		cnt&=a[i];
		cout<<cnt;
	}
	else cout<<0;
	return 0;
}
