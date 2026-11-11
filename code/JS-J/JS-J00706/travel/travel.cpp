#include<bits/stdc++.h>
using namespace std;
int nub(string v){
    return (v[0]-'0')*10+(v[1]-'0');
}
char vv(string v){
    return v[2];
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int sta_a,sta_b;
    string v_a,v_b;
    cin>>sta_a>>v_a>>sta_b>>v_b;
    //cout<<nub(v_a)<<" "<<nub(v_b);

    if(sta_a==sta_b){
        cout<<1;
    }else cout<<0;
    if(nub(v_a)==nub(v_b)&&((sta_a==sta_b))){
        cout<<1;
    }else cout<<0;
    if(((vv(v_a)<='C'&&vv(v_b)<='C')||(vv(v_a)>='D'&&vv(v_b)>='D'))&&(nub(v_a)==nub(v_b))&&(sta_a==sta_b)){
        cout<<1;
    }else cout<<0;
    if((int(abs(vv(v_a)-vv(v_b))==1&&max(vv(v_a),vv(v_b))!='D'))&&(nub(v_a)==nub(v_b))&&(sta_a==sta_b)){
        cout<<1;
    }else cout<<0;
    return 0;
}
