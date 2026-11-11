#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>a>>b;
	a=b;
	long long ans = 0;
	while(a--){
		ans+= b*a+a/b;
		cout<<ans;
	}
	return 0;
}	

