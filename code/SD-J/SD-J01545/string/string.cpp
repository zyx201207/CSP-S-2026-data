#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,n;
	string c,d;
	cin>>n;
	cin>>a>>d;
	for(int i=2;i<=n;i++){
		cin>>a>>c;
		if(c==d)
			d=c;	
}
	if(c==d)
		cout<<0;
	else cout<<2;
	return 0;
} 
