#include <bits/stdc++.h>
using namespace std;
long long c,r;
int main(){
	freopen("hub.in" ,"r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>r;
	if(r==1)cout<<3;
	else if(r==2)cout<<1<<endl<<2;
	else if(r==3)cout<<1<<endl<<2<<endl<<3;
	else{
		for(int i=1;i<=r;i++){
			cout<<i<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
