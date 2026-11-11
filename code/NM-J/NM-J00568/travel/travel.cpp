#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d,f;
    cin>>a>>b>>c>>d>>f;
    if(a==b){
        cout<<1;
    }else{
        cout<<0;
        }
    if(b==c){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c==d){
        cout<<1;
    }else{
        cout<<0;
    }
    if(d==f){
        cout<<1;
    }else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
