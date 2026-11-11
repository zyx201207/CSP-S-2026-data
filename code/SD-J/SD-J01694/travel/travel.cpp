#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string p,p2;
    int l,l2;
    
   	cin>>l>>p>>l2>>p2;
	
	if(l==l2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(p[0]==p2[0]&&p[1]==p2[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}

	if(p[2]-p2[2]<=2||p[2]-p2[2]>=-2){
		if(p[2]=='D'&&p[2]=='C'||p2[2]=='D'&&p2[2]=='C'){
            cout<<"1";
		}
		else if(p[2]=='A'&&p2[2]=='B'||p[2]=='A'&&p2[2]=='C'||p[2]=='B'&&p2[2]=='A'||p[2]=='B'&&p2[2]=='C'||p[2]=='C'&&p2[2]=='A'||p[2]=='C'&&p2[2]=='B'){
			cout<<"1";
		}
	}
	else{
		    cout<<"0";
	}
			
	

	if(p[2]-p2[2]==1||p[2]-p2[2]==-1){
        cout<<"1";
	}
	else{
		cout<<"0";
	}
    

	

    
	

}
