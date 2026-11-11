#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string s;
    int n,l,r;
    
    cin>>n;
    for(int i=0;i<n;i++){
    	int ds;
    	string fh;
    	cin>>ds>>fh;
    	for(int j=0;j<ds;j++){
    		s+=fh;
    		
		}
	}
	l=0,r=s.size()-1;
	int xgs=0;
    while(r>l){
		if(s[l]!=s[r]){
			xgs++;		
		}
		l++,r--;
	}
	cout<<xgs;

	

    
	

}
