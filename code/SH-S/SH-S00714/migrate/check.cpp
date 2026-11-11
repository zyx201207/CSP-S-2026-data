#include<bits/stdc++.h>
using namespace std;
ifstream f("migrate.out");
ifstream F("migrate1.ans");
long long m,a[100008],b;
int main(){
	while(f>>a[++m]);m--;
	for(int i=1;i<=m;i++){
		F>>b;
		if(a[i]!=b){
			cout<<"wa on line "<<i<<'\n';
			cout<<a[i]<<' '<<b<<'\n';
			return i;
		}
	}
	if(F>>b) cout<<"ole\n";
	cout<<"AC!!!";
}
