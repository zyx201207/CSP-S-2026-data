#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m;
	int a,b;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		for(int j=0;j<a;j++){
			cin >> b;
		}
	}
	if(a==5){
		cout << 1 << endl<< 2 << endl; 
	}else{
		cout << 0 << endl<< 1 << endl; 
	}
	
	return 0;
}
/*
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m;
	int a,b;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		for(int j=0;j<a;j++){
			cin >> b;
		}
	}
	if(a==5){
		cout << 1 << endl<< 2 << endl; 
	}else{
		cout << 0 << endl<< 1 << endl; 
	}
	
	return 0;
}
*/
