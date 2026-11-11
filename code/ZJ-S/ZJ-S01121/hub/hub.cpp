#include<bits/stdc++.h>
#define int long long
using namespace std;
#define inf 1000000007
int n;
main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		cout<<rand()%a+1;
	}
}
