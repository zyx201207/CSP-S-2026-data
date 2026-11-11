#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
int main(){
	freopen("card.in","a",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x==m)cnt++;
	}
	cout<<n<<" "<<m<<" "<<cnt;
	return 0;
}
