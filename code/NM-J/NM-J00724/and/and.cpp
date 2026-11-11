#include<bits/stdc++.h>
using namespace std;
string er(int q){
    int z,w=q;
    string r="",t="";
    while(q!=0){
        z=w%2;
        w=w/2;
        r+=char(z);
    }
    for(int i=r.size();i>=0;i--){
        t+=r[i];
    }
    return t;
}
int sh(string b){
    int z=b.size(),s=0,q=0;
    for(int i=z;i>=0;i--){
        s+=b[i]*pow(2,q);
        q++;
    }
    return s;
}
int he(string k,string p){
    int b=min(k.size(),p.size());
    string z="";
    for(int i=1;i<=b;i++){
        if(k[i]==p[i]){
            z+='1';
        }
        else{
            z+='0';
        }
    }
    return sh(z);
}
vector<int> a;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,cnt=0,v;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>v;
        a.push_back(v);
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<=n;j++){
            cnt=max(he(er(a[i]),er(a[j])),cnt);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
