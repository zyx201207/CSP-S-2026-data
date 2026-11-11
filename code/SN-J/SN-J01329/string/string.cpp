#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],n,ans,mn;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
	}for(int i=1,j=n;i<j;){
		mn=min(a[i],a[j]);
		if(c[i]!=c[j]){
			ans+=mn;
		}a[i]-=mn;
		a[j]-=mn;
		if(a[i]==0)++i;
		if(a[j]==0)--j;
	}cout<<ans;
	return 0;
}
