#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	srand(time(0));
	for(int i=1;i<=t;i++){
		cout<<rand()<<"\n";
	}
}
