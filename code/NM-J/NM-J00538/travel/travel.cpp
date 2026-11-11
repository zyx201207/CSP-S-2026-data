#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b;
int x=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        x++;
    }
    else{
        cout<<0;
    }


    if(x==1){
        if(s1[0]==s2[0]){
            if(s1[1]==s2[1]){
                cout<<1;
                x++;
            }
            else{
                cout<<0;
            }
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }


    if(x==2){
        if(s1[2]=='A' || s2[2]=='A'){
            if(s1[2]=='B' || s2[2]=='B') {
                cout<<1;
                x++;
            }
            else if(s1[2]=='C' || s2[2]=='C'){
                cout<<1;
                x++;
            }
        }
        else if(s1[2]=='B' || s2[2]=='B'){
            if(s1[2]=='A' || s2[2]=='A') {
                cout<<1;
                x++;
            }
            else if(s1[2]=='C' || s2[2]=='C'){
                cout<<1;
                x++;
            }
        }
        else if(s1[2]=='D' || s2[2]=='D'){
            if(s2[2]=='F' || s1[2]=='F'){
                cout<<1;
                x++;
            }
            else{
                cout<<0;
            }
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }



    if(x==3){
        if(s1[2]=='C' && s2[2]=='D'){
            cout<<0;
        }
        else if(s2[2]=='C' && s1[2]=='D'){
            cout<<0;
        }
        else if(char(s1[2])+1==s2[2]){
            cout<<1;
        }
        else if(char(s1[2])-1==s2[2]){
            cout<<1;
        }
        else if(s1[2]=='D' && s2[2]=='F'){
            cout<<1;
        }
        else if(s2[2]=='D' && s1[2]=='F'){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
