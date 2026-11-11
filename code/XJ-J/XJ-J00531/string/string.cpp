#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn];

int main(){
	
	int n;
	cin>>n;
	char c1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c1;
	}
	
	string s;
	for(int i=1;i<=n;i++){
		s+=a[i]*c1;
	}
	cout<<s;
	
	return 0;
}