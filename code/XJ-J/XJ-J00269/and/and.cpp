#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		m--;
		if(m==0){
			cout<<a[i];
			return 0;
		}
	}
	return 0;
}
