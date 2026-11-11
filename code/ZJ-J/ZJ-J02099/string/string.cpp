#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200010;
LL n,a[N],k,l,r,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		k+=a[i];
	}
	k/=2,l=1,r=n;
	while(k>0){
		int mi=min(a[l],a[r]);
		k-=mi;
		if(c[l]!=c[r]) ans+=mi;
		if(a[l]>a[r]){
			a[l]-=mi;
			r--;
		}else if(a[l]<a[r]){
			a[r]-=mi;
			l++;
		}else{
			l++,r--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
