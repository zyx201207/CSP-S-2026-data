#include<bits/stdc++.h>
using namespace std;
int n,l=1,r;
long long a[200010],ans,dl=1,dr,al[200010];
string c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		al[i]=al[i-1]+a[i];
	}
	r=n;
	dr=al[n];
	while(l<=r&&dl<dr){
		int k=min(al[l]-dl+1,dr-al[r-1]);
		if(c[l]!=c[r]){
			ans+=k;
		}
		dl+=k,dr-=k;
		if(dl>al[l])l++;
		if(dr<=al[r-1])r--;
	}
	cout<<ans<<endl;
	return 0;
}
