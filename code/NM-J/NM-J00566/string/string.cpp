#include<bits/stdc++.h>
using namespace std;
string m;
char w;
int n,a,as;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>w;
        for(int j=1;j<=a;j++){
            m[j+i]+=w;
        }
    }
    for(int i=1;i<=n;i++){
        if(m[i]!=m[n-i]){
            as++;
        }
    }
    cout<<as-1;
    return 0;
}
