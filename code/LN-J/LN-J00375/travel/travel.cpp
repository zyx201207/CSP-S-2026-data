#include <iostream>
using namespace std;
int a,b,a1,b1;
string aa,bb;
bool ch(string x,string y){
    if(x[2]<='C'&&y[2]<='C') return 1;
    if(x[2]>='D'&&y[2]>='D') return 1;
    return 0;
}
bool ch2(string x,string y){
    if(ch(x,y)){
        if(x[2]-y[2]==1||x[2]-y[2]==-1) return 1;
        return 0;
    }
    return 0;
}
void in(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
}
int main(){
    in();
   //freopen("travel1.in","r",stdin);
    cin>>a>>aa>>b>>bb;
    if(a==b) cout<<1;
    else cout<<0;
    if(aa[0]==bb[0]&&aa[1]==bb[1]&&a==b) cout<<1;
    else cout<<0;
    bool ok=ch(aa,bb);
    if(aa[0]==bb[0]&&aa[1]==bb[1]&&a==b&&ok) cout<<1;
    else cout<<0;
    bool ok2=ch2(aa,bb);
    if(aa[0]==bb[0]&&aa[1]==bb[1]&&a==b&&ok&&ok2) cout<<1;
    else cout<<0;
    return 0;
}
