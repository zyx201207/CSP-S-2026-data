#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }int a=0,b=0;
    for(int i=0;i<(int)s1.size();i++){
        if(s1[i]>='0'&&s1[i]<='9') a=a*10+s1[i];
    }
    for(int i=0;i<(int)s2.size();i++){
        if(s2[i]>='0'&&s2[i]<='9') b=b*10+s2[i];
    }if(a==b){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }char x=s1[2],y=s2[2];
    if((x<='C'&&y<='C')||(x>'C'&&y>'C')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }if(abs((int)x-y)==1&&(x<='C'&&y<='C')){
        cout<<1;
    }else if(x>'C'&&y>'C'){
        cout<<1;
    }else cout<<0;
    return 0;
}
