#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],x,ans,cn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int j=0;j<t;j++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			x=a[i]+d+1;
			for(int k=i;k<n;k++){
				if(a[k]==x)
					cn++;
			}
			if(cn==2)
				ans++;
			cn=0;
		}
		cout<<ans<<endl;
		ans=0;
	}
}
