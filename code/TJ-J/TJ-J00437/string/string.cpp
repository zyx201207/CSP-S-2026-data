#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200005];
string b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	int l=0,r=n-1;
	long long ans=0;
	while(l<r){
		if(b[l]!=b[r]){
			ans+=min(a[l],a[r]);
		}
		if(a[l]<a[r]){
			a[r]-=a[l];
	 		l++;
		}else if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
