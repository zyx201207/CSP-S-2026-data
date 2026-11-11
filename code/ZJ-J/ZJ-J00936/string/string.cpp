#include<bits/stdc++.h>
using namespace std;
int n,l=1,r,d=0,ans=0;
long long a[200005];
string b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	r=n;
	for (int i=1;i<=n;i++){
	    if(a[l]+d<=a[r]){
	    	if(b[l]!=b[r]){
	    		ans+=a[l]+d;
			}
			d=a[r]-a[l];
	    	l++;
		}else{
			if(b[l]!=b[r]){
	    		ans+=a[r];
			}
			d=a[r]-a[l];
			r--;
		}
	}
	cout<<ans;
	return 0;
}