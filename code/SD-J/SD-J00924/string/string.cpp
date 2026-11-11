#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int c[N],ans,n,l=1,r;
char a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)    cin>>c[i]>>a[i];
	r=n;
	while(l<r){
		if(c[l]<c[r]){
			if(a[l]==a[r])    c[r]-=c[l],l++;
			else    c[r]-=c[l],ans+=c[l],l++;
		}else{
			if(a[l]==a[r])    c[l]-=c[r],r--;
			else    c[l]-=c[r],ans+=c[r],r--;
		}
	}cout<<ans;
	return 0;
}//100
