#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,h=0;
	string a;
	string b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	int len=a.length();
	int lenb=b.length();
	for(int i=0;i<lenb;i++){
		if(b[i]=b[i+1]){
			cout<<"0";
		}
		if(b[i]!=b[i+1]){
			h++;
			n=n-h;
		}
	}
	cout<<n;
	return 0;
}