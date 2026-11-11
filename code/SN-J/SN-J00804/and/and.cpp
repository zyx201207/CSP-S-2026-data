//SN-J00804 张馨月 西安翱翔中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
	cout<<ans;
	
	return 0;
}
