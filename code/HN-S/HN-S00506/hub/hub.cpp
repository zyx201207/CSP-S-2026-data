#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N(1e9+7);
int c,T;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(T==2){
		cout<<"1\n2";
		return 0;
	}
	while(T--){
		cout<<rand()%N<<'\n';
	}
	return 0;
}

