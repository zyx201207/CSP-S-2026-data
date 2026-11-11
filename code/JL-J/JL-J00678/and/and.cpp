#include <bits/stdc++.h>
using namespace std;
string er(int a){
    string t="";
    while(a>1){
        if(a%2==0){
            t+='0';
        }else{
            t+='1';
        }
        a=a/2;
    }
    t+='1';
    return t;
}
int shi(string s){
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            ans+=pow(2,i);
        }
    }
    return ans;
}
int aand(int a,int b){
    string sa=er(a),sb=er(b),t="";
    int o;
    if(sa.size()>sb.size()){
        o=sa.size();
    }else o=sb.size();
    for(int i=0;i<o;i++){
        if(sa[i]=='1'&&sa[i]==sb[i]){
            t+='1';
        }else t+='0';
    }
    return shi(t);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> a;
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        a.push_back(b);
    }
    sort(a.begin(),a.end());
    int me=0;
    int l=0,r=a.size()-1;
    for(int i=0;i<n-m+1;i++){
        int b=a[i];
        for(int j=0;j<m;j++){
            b=aand(b,a[i+j]);
        }
        if(b>me)me=b;
    }
    cout<<me;
    return 0;
}
