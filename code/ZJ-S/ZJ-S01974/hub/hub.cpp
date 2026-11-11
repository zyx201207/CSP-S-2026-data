#include <bits/stdc++.h>
using namespace std;
int C,T,n;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>C>>T;
	while(T--){
		cin>>n;
		cout<<((rand()%n)*(rand()%n))%n<<"\n";
	}
	return 0;
}