#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200020];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==0){
		cout<<0<<endl;
	}
	else if(m=0){
		cout<<0<<endl;
	}
    else{
	    cout<<n<<endl;
	}
	return 0;
}
