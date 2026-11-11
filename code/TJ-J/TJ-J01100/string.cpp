#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long len=0,ans=0;
char c[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int l=1,r=n;
	for(int i=1;len>0;i++){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}
		len-=2*min(a[l],a[r]);
		if(a[l]>a[r]){
			a[l]-=a[r--];
		}else if(a[l]<a[r]){
			a[r]-=a[l++];
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
