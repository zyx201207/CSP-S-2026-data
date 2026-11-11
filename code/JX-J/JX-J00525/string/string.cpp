#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,t;
    long long sum=0;
    char e;
    cin>>n;
    string h;
    for(int i=0;i<n;i++){
        cin>>t>>e;
        while(t--)h+=e;
    }
    int u=h.length();
    for(int i=0;i<u;i++){
        if(h[i]!=h[u-i-1]){
            sum++;
        }
    }
    cout<<sum/2;
}
