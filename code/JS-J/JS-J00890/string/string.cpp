#include<bits/stdc++.h>
using namespace std;
int s;
int s3[100005];
char c;
int s2;
int t;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s2>>c;
        s+=s2;
        for(int j=s-s2+1;j<=s;++j){
            s3[j]+=c-'a';
        }
    }
    for(int i=1;i<=s/2;++i){
        if(s3[i]!=s3[s-i+1])++t;
    }
    cout<<t<<"\n";


    return 0;
}
