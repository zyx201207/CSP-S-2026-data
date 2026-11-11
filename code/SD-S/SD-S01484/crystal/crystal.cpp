#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,maxx=0,cnt;
int a[N],d[N]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	for(int l=1,r=2;r<=n;r++){
		m-=d[r]*(r-l);
		if(m<0){
			while(m<0){
				m+=a[r]-a[l];
				l++;
			}
		}
		maxx=max(maxx,r-l+1);
	}
	cout<<maxx;
	return 0;
}
//14:49

