#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w"stdout);
	long long a,b,w,r[101];
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>r[i]; 
	} 
	for(int i = 0;i<b;i++){
		w = r[i] and r[i+1];
	}
	cout<<w;
	return 0;
}
