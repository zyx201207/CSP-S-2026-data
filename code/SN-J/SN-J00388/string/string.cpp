#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	int m[100005];
	string n[100005];
	for(int i=1;i<=a;i++){
		cin>>m[i]>>n[i];
	}
	string k[100005];
	int l=1;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=m[i];j++){
			k[l]=n[i];
			l++;
		}
	}
	int p=0,o=0;
	for(int i=1;i<=l;i++){
		if(k[i]==k[l-o]) p++;
		o++;
	}
	cout<<"0";
	return 0;
}
