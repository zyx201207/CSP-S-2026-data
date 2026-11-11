#include<bits/stdc++.h>
using namespace std;

int c1,c2,s1,s2;
char si,sj;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    
    cin>>c1>>s1>>si>>c2>>s2>>sj;
    
        if(c1==c2){
            cout<<1;
            if(s1==s2){
                cout<<1;
                if(si>='A'&&si<='C'&&sj>='A'&&sj<='C'){
                    cout<<1;
                    if(si+1==sj||si-1==sj){
						if(s1==s2||s1+1==s2||s2+1==s1){
                        cout<<1;
						}
                    
                    }else{
                        cout<<"0";
                    }
                }else if(si>='D'&&si<='F'&&sj>='D'&&sj<='F'){
                    cout<<1; 
                    if(s1==s2||s1+1==s2||s2+1==s1){
                        cout<<1;
                    }else{
                        cout<<"0";
                    }
                }else{
                    cout<<"00";
                }
            }else{
                cout<<"000";
            }
            
            
        }else{
            cout<<"0000";
            return 0;
        }
        
    
    return 0;
}
