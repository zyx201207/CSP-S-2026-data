#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int e;
    for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        e+=a;
        for(int i=1;i<=a;i++){
            s+=b;
        }
    }
    int sum=0;
    for(int i=1;i<=e/2;i++){
        if(s[i]-'a'!=s[e-i]-'a'){
            sum++;
        }
    }
    cout<<sum;
    //qu xiao zhu shi.
    return 0;
}
