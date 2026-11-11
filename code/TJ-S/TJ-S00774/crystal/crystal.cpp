#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,maxl=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int sum=0,len=1,f=0;
		for(int j=i+1;j<=n;j++){
			sum+=a[i]-a[j];
			if (sum>m){
				f=1;
				maxl=max(maxl,len);
				break;	
			}
			len++;
		}
		if (!f) maxl=max(maxl,len);
	}
	cout<<maxl;
	return 0;
}

