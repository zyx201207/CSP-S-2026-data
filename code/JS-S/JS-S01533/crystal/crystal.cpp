#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N];
__int128 c[N];
bool check(int i,int j){
	__int128 tmp=(j-i+1)*a[j]+c[i-1]-c[j];
	//cout<< i << j << (long long)tmp <<'\n';
	return tmp<=(__int128)m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+(__int128)a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i,mid)){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,r-i+1);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
