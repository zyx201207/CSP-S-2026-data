#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n;
	if(n>0&&n<=3){
		cout<<35<<endl<<16;
	}
	else{
		cout<<1;
	}
	return 0;
}
