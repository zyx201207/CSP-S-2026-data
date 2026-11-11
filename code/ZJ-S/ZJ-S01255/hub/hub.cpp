#include<bits/stdc++.h>
using namespace std;
long long c,T;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	long long x=T;
	while(T--){
		cout<<x-T+1<<endl;
	}
	return 0;
}



