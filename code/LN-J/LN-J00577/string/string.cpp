#include<bits/stdc++.h>
using namespace std;
void init(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
}
int main(){
    init();
    int n;
    cin>>n;
    long long a,k=0,l=0;
    char c;
    string h="";
    for(int i=0;i<n;i++){
        cin>>a>>c;
        l+=a;
        for(int j=0;j<a;j++){
            h+=c;
        }
    }
    long long u=l/2;
    while(u){
        if(h[l-u] != h[u-1]){
            k++;
        }
        u--;
    }
    cout<<k<<endl;
}
