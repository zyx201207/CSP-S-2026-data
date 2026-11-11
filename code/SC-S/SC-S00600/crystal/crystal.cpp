#include<bits/stdc++.h>
using namespace std;
long long int m,n,a[500005],b[500005],l=1,maxn,ans; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		maxn+=(i-l)*(a[i]-a[i-1]);
		for(;l<=i;l++){
			//cout<<"---maxn="<<maxn<<"---l="<<l<<endl;
			if(maxn<=m){
				break;
			}
			maxn-=(a[i]-a[l]);
		}
		//cout<<"---"<<i<<"---"<<l<<endl;
		ans=max(ans,(i-l+1));
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
5 5
1 2 9 8 4
*/