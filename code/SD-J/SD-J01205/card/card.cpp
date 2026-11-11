#include <bits/stdc++.h>
using namespace std;
const int M=5e5;
int n,m,a[M+5],l[M+5],nx[M+5],ans[M+5];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=m;i++){
		l[i]=n+1;
	}
	for (int i=n;i>=1;i--){
		nx[i]=l[a[i]];
		l[a[i]]=i;
	}
	for (int cas=1;cas<=n;cas++){
		for (int i=cas;i<=n;i++){//cout<<i<<" "<<a[i]<<"	";
			ans[a[i]]++;
			while (nx[i]!=n+1){
				i=nx[i];
			}
		}//cout<<endl;
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
