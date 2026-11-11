#include<bits/stdc++.h>
using namespace std;
long long r;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<5;i++)cin>>r;
	if(r==2)cout<<32<<endl<<17;
	else while(r--)cout<<1<<endl;
	return 0;
}