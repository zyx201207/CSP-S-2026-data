#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if (n<=5000){
		for (int i=1;i<=n;i++){
			int cnt=0,flag=0;
			for (int j=i-1;j>=1;j--){
				cnt+=a[i]-a[j];
				if (cnt>m){
					ans=max(ans,j-i+1);
					flag=1;
					break;
				}
			}
			if (flag==0) ans=max(ans,i);
		}
		cout<<ans<<endl;
		return 0;
	}
	int gs=m/(a[2]-a[1]);
	for (int i=1;i<=n;i++){
		if (i*(i-1)/2>gs){
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}
