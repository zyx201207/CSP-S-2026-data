#include <iostream>
using namespace std;
int a,c,e=0;
string b="",d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>c>>d;
		for(int j=0;j<c;j++){
			b+=d;
		}
	}for(int i=0;i<b.length();i++){
		if(b[i]!=b[b.length()-1-i]){
			++e;
		}
	}cout<<e/2;
	return 0;
}
