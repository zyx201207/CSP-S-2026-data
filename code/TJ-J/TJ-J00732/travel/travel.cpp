#include<bits/stdc++.h>
using namespace std;
int main (){
    freopen("travel.in","r",stdin);
    freopen("travel.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char c1;
    char s1;
    char c2[3];
    char s2[3];
    cin>>c1>>s1>>c2>>s2;
    int chexiang=0;
    int pai=0;
    int ce=0;
    int xianglin=0;

    if(s1==c1){
        chexiang=1;
    }
    if(c2[0]==s2[0]&&c2[1]==s2[1]){
        pai=1;
    }
    if(c2[2]-s2[2]==1){
        if(c2[2]!=C&&c2[2]!=D){
            ce=1;
        }
        else if(c2[2]==C&&s2[2]!=D){
            ce= 1;
        }
        else if(c2[2]!=C&&s2[2]==D){
            ce=1;                          
        }
    }
    else if(c2[2]==C&&s2[2]==A){
        ce=1;
    }
    else if(s2[2]==C&&c2[2]==A){
        ce=1;
    }
    if(ce==1){
        if(c2[2]-s2[2]==1){
            xianglin=1;
        }
        else if(s2[2]-c2[2]==1){
            xianglin=1;
        }
        else if(c2[2]==D&&s2[2]==F){
            xianglin =1;
        }
        else if(s2[2]==D&&c2[2]==F){
         sssssssssslse{
        xianglin=0;
    }
    cout<<chexiang<<pai<<hang<<xianglin;
    return 0;
}