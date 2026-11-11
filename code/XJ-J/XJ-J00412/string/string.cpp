#include<bits/stdc++.h>
using namespace std;
string a="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	int s=0;
	for(int i=0;i<n;i++){
		int j;
		char az;
		cin>>j>>az;
		s+=j;
		a+=az*j;
	}
	s/=2;
	int g=0;
	for(int i=0;i<s;i++){
		if(a[i]!=a[s-1-i]){
			g+=1;
		}
	}
	cout<<g;
	return 0;
}
