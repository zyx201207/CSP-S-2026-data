#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int w[3],l[3];//w is pai;l is lie;
bool ans[5]; 
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    int index=0;
    if(c1==c2){
        ans[1]=1;
    }
    if(!ans[1]){
        cout<<"0000";
        return 0;
    }
    index=0;
    w[1]=(s1[0]-'0')*10+s1[1];
    w[2]=(s1[0]-'0')*10+s2[1];
    switch(s1[2]){
        case 'A':
            l[1]=1;
            break;
        case 'B':
            l[1]=2;
            break;
        case 'C':
            l[1]=3;
            break;
        case 'D':
            l[1]=4;
            break;
        case 'E':
            l[1]=5;
    }
    switch(s2[2]){
        case 'A':
            l[2]=1;
            break;
        case 'B':
            l[2]=2;
            break;
        case 'C':
            l[2]=3;
            break;
        case 'D':
            l[2]=4;
            break;
        case 'E':
            l[2]=5;
    }
    if(w[1]!=w[2]){
        cout<<"1000";
        return 0;
    }
    ans[2]=1;
    if(!(l[1]<=3&&l[2]<=3||l[1]>=4&&l[2]>=4)){
        cout<<"1100";
        return 0;
    }
    ans[3]=1;
    if(l[1]==1||l[1]==3){
        if(l[2]==2){
            cout<<"1111";
        }else{
            cout<<"1110";
        }
    }
    if(l[1]==2){
        if(l[2]==1||l[2]==3){
            cout<<"1111";
        }else{
            cout<<"1110";
        }
    }
    if(l[1]==4){
        if(l[2]==5){
            cout<<"1111";
        }else{
            cout<<"1110";
        }
    }
    if(l[1]==5){
        if(l[2]==4){
            cout<<"1111";
        }else{
            cout<<"1110";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}