//8:43 9:08
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n;
int a[maxn],A[maxn];
char c[maxn],C[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		A[n-i+1]=a[i];
		a[i]+=a[i-1];
		C[n-i+1]=c[i];		
	}
	for(int i=1;i<=n;i++){
		A[i]+=A[i-1];
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" "<<A[i]<<"\n";
//	}
//	if(a[n]%2) {
//		return 1;
//	}
	int idx=1,lt=1,rt=1,ans=0;
	while(lt<=n&&rt<=n){
		if(c[lt]==C[rt]){
			idx=min(a[lt],A[rt])+1;
			if(idx-1==a[lt]) lt++;
			if(idx-1==A[rt]) rt++;
		}else{
			ans=ans+min(a[lt],A[rt])-idx+1;
			idx=min(a[lt],A[rt])+1;
			if(idx-1==a[lt]) lt++;
			if(idx-1==A[rt]) rt++;
		}
	}
	cout<<ans/2;
	return 0;
}
/**
dududu
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
**/
