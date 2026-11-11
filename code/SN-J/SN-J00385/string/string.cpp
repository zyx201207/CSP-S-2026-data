#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	queue<string>q;
	for(int i=0;i<n;i++){
		long long a;
		string c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			q.push(c);
		}
	}
	if(n==1)cout<<0;
	if(n==2)cout<<0;
	else{
		int b=(q.size()/2)+1;
		cout<<b;
	}	
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/


