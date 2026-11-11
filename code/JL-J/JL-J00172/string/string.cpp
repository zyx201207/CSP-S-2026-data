#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    char c;
    int a,t=0,p=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=p;j<=a-1;j++){
            s[j]=c;
            p++;
        }
    }
    int l=s.size();
    for(int i=0;i<=(l-1)/2;i++){
        if(s[i]!=s[l+1-i]){
            t++;
        }
    }
    cout<<t;
    return 0;
}
