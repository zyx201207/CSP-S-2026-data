#include <bits/stdc++.h>
using namespace std;
int a[200005];
string b[200005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n;
	string s={};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s=s+b[i];
		}
	}
	int i=0;
	int l=s.size();
	for(int j=0;j<l/2;j++){
		if(s[j]!=s[l-j-1]){
			i++;
		}
	}
	cout<<i;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
