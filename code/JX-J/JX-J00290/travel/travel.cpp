#include<bits/stdc++.h>
using namespace std;
bool pd(char a,char b){
    if((a=='F'&&b=='D')||(a=='F'&&b=='D')){
        return 1;
    }
    if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
        return 1;
    }
    return 0;
}
int a,b;
char c,d;
int aa,bb;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    cin>>a>>aa>>c>>b>>bb>>d;
        if(a==b){
        cout<<1;
    }else{
        cout<<0;
    }
    if(a==b&&aa==bb){
        cout<<1;
    }else{
        cout<<0;
    }
    if(a==b&&aa==bb&&pd(c,d)==1){
        cout<<1;
    }else {
        cout<<0;
    }
    if(a==b&&((abs(aa-bb)==1&&c==d)||(abs(c-d)==1&&aa==bb&&c!='C'&&c!='D'&&d!='C'&&d!='D'))){
        cout<<1;
    }else{
        cout<<0;
    }
}
