#include<bits/stdc++.h>
using namespace std;

int main (){
freopon("string.in","r","stdin");
freopon("string.out","w","stdout");
	int n;
	cin >>n;
	string w;
	int q=0;
	for(int i=0;i<n;i++){
			int a;
		char c;
		cin>>a>>c;
		w+=a*c;
		}
			for(int i=0;i<w.size()/2;i++){
				if(w[i]!=w[w.size()-1-i]){
					q++;
					}
				}
				cout <<q;
	return 0;
}
