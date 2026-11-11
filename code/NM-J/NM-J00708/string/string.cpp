#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n ;
	string s ={};
	cin>>n ;
	for(int i= 0 ; i<n ; )
	string d ;
	cin>>s;
	int i = 0;
	int l = s.size();
	for(int j =0 ; j<l/2 ; j++){
		if(s[j]== s[l - j-1]){
		i++;
		}
	}
	cout <<i ;
	return 0 ;
	
	}
