#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int m,x,sum=0;
    string s,s1;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>s1;
        for(int j=1;j<=x;j++){
            s+=s1;
        }
    }
    for(int i=1;i<=s.size()/2;i++){
        if(s[i]==s[s.size()-i+1]){
            continue;
        }
        else{
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
