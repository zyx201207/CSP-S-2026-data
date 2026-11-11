#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,d,a[2000005],s[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d>>a[1];
		int la=1,ans=0;
		for(int i=2;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[la]<=d)s[i]=i-la;
			else{
				while(a[i]-a[la]>d&&la<i)la++;
				s[i]=i-la;
			}
		}
		for(int i=3;i<=n;i++){
			if(s[i]==2)ans+=s[i-1]-1;
		}
		cout<<ans<<"\n";
	}
	
}
