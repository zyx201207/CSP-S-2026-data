#include<bits/stdc++.h>
using namespace std;
string s;
int sum=0,id=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	char b[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]!=s[id]){
			sum++;
		}
		id++;
	}
	cout<<sum/2;
	return 0;
}
