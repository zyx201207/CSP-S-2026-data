#include <bits/stdc++.h> 
using namespace std;
int n[50003];
long long int a,m,x;
int c,q,g;
int main(){
	freopen("crystal.in","r"stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>m;
	for(int i =1;i<=c;i++){
		cin>>n[i];
	}
	int maxd =n[1],b,z;
	for(int j = 1;j<=c;j++){
	    for(int i =2;i<=c-g;i++){
		    if(n[i]>=maxd){
			    maxd = n[i];
    			z = i;
		    }
    	}
	    b =n[c];
	    n[c] = maxd;
    	n[z] = b;
    	g++;
	}
	
	for(int i =c/2;i<=1;i--){
		if((n[i]-n[i-1])<m&&(x+n[i]-n[i-1]<m)){
			x+=n[i]-n[i-1];
			q+=1;
		} 
		else{
			break;
		}
	}
	cout<<q;
	return 0;
}
