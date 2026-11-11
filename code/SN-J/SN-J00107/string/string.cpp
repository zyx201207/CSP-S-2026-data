#include<bits/stdc++.h>
using namespace std;
struct ab{
	int a;
	string b;
}abc[10005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>abc[i].a>>abc[i].b;
	}
	bool y=true;
	for(int i=0;i<n;i++){
		if(abc[i].b!=abc[i+1].b){
			y=false;
		}
	}
	if(y==false){
		cout<<'0';
	}
	else{
		long long h=0;
		for(int i=0;i<n;i++){
			h=h+abc[i].a;
		}
		cout<<h%2;
	}
	return 0;
}

