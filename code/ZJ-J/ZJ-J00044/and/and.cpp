#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],ans,ma;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		a[i]=x;
		ma=max(x,ma);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]<ans)continue;
		long long sum=0;
		for(int j=i+1;j<=i+m-1;j++){
			if(j==i+1){
				sum=a[i]&a[j];
			}else{
				sum=sum&a[j];
			}
		}
		ans=max(sum,ans);
	}
	cout<<ans;
	
	
	return 0;
}
