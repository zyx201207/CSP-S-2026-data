#include<bits/stdc++.h>
using namespace std;
int n,byyd = 0;
string s,ops;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i = 0;i<n;i++){
        int dsg;
        char zm;
        cin>>dsg>>zm;
        while(dsg--){
            ops+=zm;
        }
    }
    s = ops;
    reverse(ops.begin(),ops.end());

    for(int i = 0;i<s.size();i++){
        if(s[i]!=ops[i])byyd++;
    }
    cout<<byyd/2;

    return 0;
}
