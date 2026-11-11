//考号：SN-J00760  姓名：刘浩宇  学校：西安市汇知中学 
#include<bits/stdc++.h>
#define int long long int
#define IOS ios::sync_with_stdio(false);
using namespace std;
int n,a[200005],l,r,ans,z;
char b[200005];
signed main(){
	IOS
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		z+=a[i];
	}
	l=1,r=n;
	while(l+1<r){
		if(b[l]!=b[r]){
			ans+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else if(a[r]>a[l]){
			a[r]-=a[l];
			l++;
		}
		else{
			l++;
			r--;
		}
	}
	if(l!=r){
		if(b[l]!=b[r]){
			ans+=min(a[l],a[r]);
		}
	}
	cout<<ans;
	return 0;
}
