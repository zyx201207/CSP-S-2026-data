#include<bits/stdc++.h>
using namespace std;
int n,x,g;
string c,s;
int main(){
//    freopen("string.in","r",stdin);
//    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        while(x--){
            s+=c;
        }
    }
    int k=s.size();
    for(int i=0;i<(s.size()+1)/2;i++){
        if(s[i]!=s[--k]){
            g++;
        }
    }
    cout<<g;
    return 0;
}
//please help me RP++
