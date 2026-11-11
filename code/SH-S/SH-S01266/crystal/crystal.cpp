#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],diff[500005],ans,ret,pos=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		diff[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		while(ret+(i-pos)*diff[i]>m){
			if(i!=pos+1){
				ret=ret-(a[i-1]-a[pos]);
				pos++;
			}else{
				pos++;
				i++;
			}
		}
		ret+=(i-pos)*diff[i];
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
