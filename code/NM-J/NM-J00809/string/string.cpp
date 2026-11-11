#include<bits/stdc++.h>

using namespace std;

int main(){
	string c,S,S1;
	int n,a,m;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a>>c;
		for(int j = 0;j<a;j++){
			S += c;
		}
	}for(int i = S.size()-1;i>=0;i--){
		S1 += S[i];
	}for(int i = S.size()-1;i>=0;i--){
		if(S[S.size()-1-i] != S1[i]){
			m++;
		}
	}cout<<m;
    return 0;
}
