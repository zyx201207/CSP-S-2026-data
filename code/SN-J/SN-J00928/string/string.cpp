#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	string b;
	int c[a];
	int d=0;
	int e=0;
	for(int i=0;i<a;i++){
		cin>>c[i];
		d=d+c[i];
		for(int j=0;j<c[i];j++){
			cin>>b[j];
		}
	}
	for(int i=0;i<d;i++){
		if(b[i]==b[1]){
			cout<<"0";
			return 0;
		}
		else{
		b[1]=b[i]&&b[i=b[1]]
		e++;
		}
	}
	cout<<e;
	return 0;
}
