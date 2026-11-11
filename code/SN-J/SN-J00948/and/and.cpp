#include<bits/stdc++.h>
using namespace std;

int n[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c=0;
	for(int i=0;i<a;i++){
		cin>>n[i];
		c+=1;
	}
	cout<<n[c/2];
	
	return 0;
}
