#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],o,ans;
//int M=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//M=max(M,a[i]);
	} 
	sort(a+1,a+1+n);
	int v=0;
	for(int i=1,j=1;i<=n;i++){
		v=v+(a[i]-a[i-1])*(i-j);
		if(v>m){
			for(int p=j;;p++){
				v-=a[i]-a[p];
				j++;
				if(v<=m){
					break;
				}
			} 
		}
		ans=max(ans,i-j+1);
	} 
	cout<<ans;
	return 0;
} 
