#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,a1,b,b1;
    cin>>a>>a1>>b>>b1;
    bool f=true,t=true;
    for(int i=0,j=0;i<2;i++,j++){
        if(a[i]!=b[j]) f=false;
    }
    if(f) cout<<1;
    else cout<<0;
    for(int i=0,j=0;i<2;i++,j++){
        if(a1[i]!=b1[j]) f=false;
    }
     if(f) cout<<1;
     else{
        cout<<0;
        f=false;
        t=false;
     }
     map<char,int> w;
     w['A']=1;
     w['B']=2;
     w['C']=3;
     w['D']=4;
     w['E']=5;
     if((w[a1[2]]<=3&&w[b1[2]]<=3||w[a1[2]]>3&&w[b1[2]]>3)&&f&&t){
            cout<<1;
        if(w[a1[2]]==1&&w[b1[2]]==2||w[a1[2]]==2&&w[b1[2]]==3||w[a1[2]]==4&&w[b1[2]]==5&&f)
           cout<<1;
        else{
            cout<<0;
        }
     }
     else{
        cout<<0;
        cout<<0;
     }
fclose(stdin);
fclose(stdout);
return 0;
}
