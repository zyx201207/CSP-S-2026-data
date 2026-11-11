//马知遥 西安交通大学附属中学 SN-J00651 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int i=n,ans=a[n];
	m--;
	i--;
	while(m--){
		ans=ans&a[i];
		i--;
	}
	cout<<ans;
}

