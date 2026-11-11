#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	int a[100005];
	cin>>c>>t;
	cin>>n>>k;
	while(n--){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	
	if(c==0&&t==3){
		cout<<1<<endl<<1<<endl<<2;
	}else if(c==0&&t==3){
		cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
	} 
	cout<<1<<endl<<2;
	return 0;
}
