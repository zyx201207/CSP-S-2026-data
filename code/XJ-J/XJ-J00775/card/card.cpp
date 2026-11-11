#include<bits/stdc++.h>
using namespace std;
int n[10000];
int main(){
	
	int a,b;
	cin>>a>>b;
	for(int i=0;i<=a;i++){
		cin>>n[i];
		if(b[i-1]<=a[i]){
			cout<<a[i];
		}
	}
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	return 0;
}