#include <bits/stdc++.h>
 
using namespace std;

int a,b,c,d;
char x,y;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a>>b>>x>>c>>d>>y;
    if(a!=c) {
    cout<<"0000";

    }
	else{
	cout<<"1";
	if(b!=d){
        cout<<"000";
       
        }
    else{
        cout<<"1";
        if(x<'D'&&y>'C'||x>'C'&&y<'D'){
            cout<<"00";
          
        }
        else{
            cout<<"1";
            if(x-y==1||x-y==-1){
                cout<<"1";
               
            }
            else {
                cout<<"0";
              
            }
        }
    }
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
   
}
