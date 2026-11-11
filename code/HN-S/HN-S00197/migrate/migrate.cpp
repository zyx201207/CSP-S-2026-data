#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main (){
	int n,d;
	int a[5050];
	cin>>c>>t;
	while(t--){
		int ana; 
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ana=a[1];
		}
		cout<<ana;
	}
	return 0;
}
