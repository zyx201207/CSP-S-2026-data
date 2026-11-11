#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],l=1,r=1,s,ans;
char b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s+=a[i];
	}
	r=n;
	while(r!=l){
		if(b[l]!=b[r]){
			ans+=min(a[l],a[r]);
		}
		int awa=min(a[l],a[r]);
		if(awa==a[l]&&awa==a[r]){
			l++;
			r--;
		}else if(awa==a[l]){
			a[r]-=a[l];
			l++;
		}else{
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
