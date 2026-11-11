#include <bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[N];
	int cnt1=0,cnt2=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt1++;
		if(a[i]==2) cnt2++;
	}
	if(a[n]==1) cout<<n<<" "<<cnt2;
	if(a[n]==2) cout<<cnt1<<" "<<n;
	return 0;
} 
