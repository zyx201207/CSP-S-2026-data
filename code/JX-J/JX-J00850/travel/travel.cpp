#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    string a1,b1;
    cin>>a>>a1>>b>>b1;
    c=a1[2]-"0";
    d=b1[2]-"0";
    if(a==b){
        cout<<1;
    }
    else{
        cout<<0000;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(a1[0]==b1[0] and a1[1]==b1[1]){
        cout<<1;
    }
    else{
        cout<<000;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(a1[2]<="C" and b1[2]<="C"){
        cout<<1;
        if(c+1==d or c-1==d){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else if(a1[2]>"C" and b1[2]>"C"){
        cout<<1;
        if(c+2==d or c-2==d){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<00;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
