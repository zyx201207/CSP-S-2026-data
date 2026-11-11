#include<bits/stdc++.h>
using namespace std;
string s,tmp;
int a;
char c;
int n;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a>>c;
        for(int j=1; j<=a; j++){
            s+=c;
        }
    }
    tmp=s;
    reverse(tmp.begin(),tmp.end());
    if(s==tmp){
        cout<<0;
        return 0;
    }
    int p=(int(s.length())-1)/2;
    int cnt;
    for(int i=0; i<=p; i++){
        if(s[i]!=tmp[i]){
            ++cnt;
        }
    }
    cout<<cnt;
    return 0;
}
