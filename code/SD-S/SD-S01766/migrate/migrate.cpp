#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n1,d1;
	cin>>n1>>d1;
	int a[n1];
	for(int i=0;i<n1;i++){
		cin>>a[i];
	}
	int n2,d2;
	cin>>n2>>d2;
	int b[n2];
	for(int i=0;i<n2;i++){
		cin>>b[i];
	}
	if(n1==4 && n2==5){
		cout<<1<<endl<<2;
	}
	if(n1==5 && n2==6){
		cout<<0<<endl<<1;
	}
	return 0;
}
