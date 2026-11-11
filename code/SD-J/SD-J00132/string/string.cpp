#include<bits/stdc++.h>
using namespace std;
struct f{
	long long g;
	char z;
};
string s;
int han(string a){
	long long c=0;
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1]) c++;
	}
	return c;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	f a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].g>>a[i].z;
		for(int j=0;j<a[i].g;j++){
			s+=a[i].z;
		}
	}
	cout<<han(s);
	return 0;
}
