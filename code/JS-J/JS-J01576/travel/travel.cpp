#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a1,a2,b1,b2;
int cx1,hs1,zw1,cx2,hs2,zw2;
bool same_side(int x,int y){
    if(x<=3&&y<=3){
        return 1;
    }else if(x>=4&&y>=4){
        return 1;
    }
    return 0;
}
bool next_to(int x,int y){
    if(abs(x-y)==1&&same_side(x,y)){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a1>>a2>>b1>>b2;
    for(int i=0;i<a1.size();i++){
        cx1=cx1*10+(int)(a1[i]-'0');
    }
    for(int i=0;i<b1.size();i++){
        cx2=cx2*10+(int)(b1[i]-'0');
    }
    for(int i=0;i<a2.size();i++){
        if(a2[i]>='0'&&a2[i]<='9'){
            hs1=hs1*10+(int)(a2[i]-'0');
        }else{
            if(a2[i]=='F'){
                zw1=5;
            }else{
                zw1=(int)(a2[i]-'A')+1;
            }
        }
    }
    for(int i=0;i<b2.size();i++){
        if(b2[i]>='0'&&b2[i]<='9'){
            hs2=hs2*10+(int)(b2[i]-'0');
        }else{
            if(b2[i]=='F'){
                zw2=5;
            }else{
                zw2=(int)(b2[i]-'A')+1;
            }
        }
    }
    cout<<(cx1==cx2)<<((cx1==cx2)&&(hs1==hs2))<<(((cx1==cx2)&&(hs1==hs2))&&same_side(zw1,zw2))<<((((cx1==cx2)&&(hs1==hs2))&&same_side(zw1,zw2))&&next_to(zw1,zw2));
    return 0;
}
// orz rp++ csp-j1= made by cici
// all right 100pts
