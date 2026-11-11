#include<bits/stdc++.h>
using namespace std;
string name="hub";int n=6,i;
int main(){
	for(i=1;i<=n;i++){
		cout<<"Running test #"<<i<<"...\n";
		system((name+".exe <"+name+char(i+48)+".in >"+name+".out").c_str());
		if(system(("fc "+name+".out "+name+char(i+48)+".ans").c_str()))cout<<"WA!\n";
		else cout<<"AC\n\n";
	}
	system("pause");
}
