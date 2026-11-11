#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int a,b;
    char c[3],d[3];
    cin>>a;
    for(int i=0;i<3;i++){
    	cin>>c[i];
	}
	cin>>b;
	for(int j=0;j<3;j++){
    	cin>>d[j];
	}
	if(a==b){
		cout<<1;
		if(c[0]*10+c[1]==d[0]*10+d[1]){
    	    cout<<1;
    	    if(c[2]=='A' && d[2]=='B'||d[2]=='C'){
                cout<<1;
	        }	
	        else if(c[2]=='B' && d[2]=='A'||d[2]=='C'){
		        cout<<1;
	        }
	        else if(c[2]=='C' && d[2]=='A'||d[2]=='B'){
		        cout<<1;
	        }
	        else if(c[2]=='D'&&d[2]=='F' || c[2]=='F'&&d[2]=='D'){
		        cout<<1;
	        }
	        else{
		        cout<<0;
		    }
	        if(c[2]=='A'&&d[2]=='B' || c[2]=='B'&&d[2]=='A'){
		        cout<<1;
	        }
	        else if(c[2]=='B'&&d[2]=='C' || c[2]=='C'&&d[2]=='B'){
		        cout<<1;
	        }
	        else if(c[2]=='D'&&d[2]=='F' || c[2]=='F'&&d[2]=='D'){
		        cout<<1;
	        }
	        else{
		        cout<<0;
	        }
	    }
	    else{
		    cout<<0<<0<<0;
	    }
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
