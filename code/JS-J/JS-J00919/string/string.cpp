#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,s1,s2;
void bd(string a,string b){
    string t="";
    long long cnt=0;
    for(int i=b.size()-1;i>=0;i--){
        t+=b[i];
    }
    b=t;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            cnt++;
        }
    }
    cout<<cnt;
}
char t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cin>>m>>t;
        cnt+=m;
        for(int j=1;j<=m;j++){
            s+=t;
        }
    }
    if(cnt%2==1){
        s1=s.substr(0,cnt/2);
        s2=s.substr(cnt/2+1,cnt/2);
        bd(s1,s2);
    }
    else{
        s1=s.substr(0,cnt/2);
        s2=s.substr(cnt/2,cnt/2);
        bd(s1,s2);
    }
    return 0;
}
