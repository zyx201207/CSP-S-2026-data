#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>T;
	while(T--){
		cin>>n;
		cout<<rand()%n+1<<"\n";
	}
}
