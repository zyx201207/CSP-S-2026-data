#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pre[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];//前缀和 
	for(int i=2;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(((i-mid+1)*a[i])-(pre[i]-pre[mid-1])<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,(long long)i-r+1);
	}//二分 
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
