#include <bits/stdc++.h> 
using namespace std;
int main(){
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		int k=(x%y-1+x)%y;
		cout<<k*(k-1);
	}
	return 0;
}
