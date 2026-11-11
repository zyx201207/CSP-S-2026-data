#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}
		
		if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}
		else if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}else{
			l++,r--;
		}
	}
	cout<<ans;
	
	
	return 0;
}