#include<bits/stdc++.h> 
using namespace std;
string a[600];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,sb;
	string zm;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>zm;
		sb+=x;
		for(int i=1;i<=x;i++){
			a[i]=zm;
		}
	}
	int RJWSM=0;
	string b[600];
	for(int i=sb;i>0;i--){
		b[i]=a[i];
	}
	for(int i=1;i<=sb;i++){
		if(b[i]!=a[i]){
			RJWSM++;	
		}
	}
	cout<<RJWSM;
	return 0;
}
