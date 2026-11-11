#include<bits/stdc++.h>
using namespace std;
string  c1, s1, c2, s2;
bool crh =false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        crh ==true;
        cout<<1;
    }else{
		crh ==false;
        cout<<0;
        
    }
    
    
    for(int i=1;i<2;i++){
        if(crh==true){
            cout<<1;
            crh ==true;
        }else{
            cout<<0;
            crh ==false;
        }
    }
    
    
    for(int i=3;i<=3;i++){
        if((s2[i]-'A')-(s1[i]-'A')<=2&&crh ==true){
            cout<<1;
            crh ==true;
        }else{
            cout<<0;
            crh ==false;
        }
    }
    
    
    for(int i=3;i<=3;i++){
        if((s1[i]-'A')>(s2[i]-'A')&&(s1[i]-'A')-(s2[i]-'A')==1&&crh ==true){
            cout<<1;
            crh ==true;
        }
		if((s1[i]-'A')>(s2[i]-'A')&&(s1[i]-'A')-(s2[i]-'A')==1&&crh ==false){
		    cout<<0;
		    crh ==false;
        }
        
		if((s1[i]-'A')==(s2[i]-'A')&&crh ==true){
            cout<<1;
            crh ==true;
        }
		if((s1[i]-'A')==(s2[i]-'A')&&crh ==false){
		    cout<<0;
		    crh ==false;
        }
        
		if((s1[i]-'A')<(s2[i]-'A')&&(s1[i]-'A')-(s2[i]-'A')==-1&&crh ==true){
            cout<<1;
            crh ==true;
        }
		if((s1[i]-'A')<(s2[i]-'A')&&(s1[i]-'A')-(s2[i]-'A')==-1&&crh ==false){
            cout<<0;
            crh ==false;
        }
    }
    return 0;
}

