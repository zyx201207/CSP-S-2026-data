#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],f[N],j[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++){
		f[i]=a[i+1]-a[i];
		j[i]=f[i]+j[i-1];
	}
	int ans=0,cnt=0,max1=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
		    ans+=f[j];
		    if(ans<=m)cnt++;
		    else{
		    	break;
			}
	    }
	    max1=max(max1,cnt);
	    cnt=ans=0;
	}
	cout<<max1;
	return 0;
}
/*
2 5 5 10
  3 3  8
    0  5
       5
*/
