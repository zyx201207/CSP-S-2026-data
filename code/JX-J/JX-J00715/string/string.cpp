#include<bits/stdc++.h>
using namespace std;
long long a[1000002],c=0,k=0,v=0;
string b;
int main(){
    int n;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
         k=max(a[i],a[i+1]);
        if(b[i]==b[i+1]){
            c++;
        }
        if(c==n-1){
        cout<<"0";
        return 0;
        }
    }
    return 0;
}
