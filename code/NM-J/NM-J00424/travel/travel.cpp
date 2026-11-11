#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel","r",stdin);
    freopen("travel","w",stdout);
    int n,m;
    string a,b;
    cin>>n>>a>>m>>b;
    char c=a[2],d=b[2];
    if(n!=m){
        cout<<0000;
        return 0;
    }else{
        for(int i=0;i<2;i++){
            if(a[i]==b[i]){
                cout<<1000;
            }
        }
    }
    int aa=0,bb=0;
    if(c>='A'&&c<='Z'){
        aa=1;
    }
    if(d>='A'&&d<='Z'){
        bb=1;
    }
    if(aa!=bb){
        cout<<1100;
    }else{
        if(abs(c-d)<=1){
            cout<<1111;
            return 0;
        }
    }
}
