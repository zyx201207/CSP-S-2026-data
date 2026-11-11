#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string .out","w",stdout);
	int n,x,a=0,z=0;
	cin >> n;
	char y;
	char s[700007];
	for(int i=1;i<=n;i++){
		cin >> x >> y;
		for(int j=z;j<x+z;j++){
			s[j]=y;
		}
        z+=x;
	}
	if(z%2==0){
	    for(int i=0;i<z/2;i++){
	        if(s[i]!=s[z-1-i]){
	    	    a++;
		    } 
        }
    }
    else{
        for(int i=0;i<(z-1)/2;i++){
	        if(s[i]!=s[z-1-i]){
	    	    a++;
		    } 
	    }
	}
    cout << a; 
    return 0;
}

