#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    std::ios::sync_with_stdio();
    std::cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<"0000\n";
        return 0;
    }
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            cout<<"000\n";
            return 0;
        }
    }
    cout<<1;
    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]>='D')){
        cout<<1;
        if(s1[2]+1==s2[2]&&s1[2]!='C'){
            cout<<1<<endl;
            return 0;
        }
        if(s2[2]+1==s1[2]&&s2[2]!='C'){
            cout<<1<<endl;
            return 0;
        }
        cout<<0<<endl;
    }
    else{
        cout<<"00\n";
    }
    return 0;
}
