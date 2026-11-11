#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N]; 
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=a[n-m+1];
	for (int i=n-m+2;i<=n;i++){
		ans=ans & a[i];
	}
	int maxx=-1;
	for (int i=1;i<=n;i++){
		int xxx=a[i];
		bool flag=true;
		for (int j=i+1;j<=i+m-1;j++){
			if (a[i] != a[j]){
				flag=false;
				break;
			}
		}
		if (flag){
			for (int j=i+1;j<=i+m-1;j++){
				xxx&=a[j];
			}
			maxx=max(maxx,xxx);
		}
	}
	cout<<max(ans,maxx);
	return 0;
}

