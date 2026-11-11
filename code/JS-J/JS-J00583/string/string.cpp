#include<bits/stdc++.h>
using namespace std;
int n;
int h[200001];
string s[200001];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i]>>s[i];
    }
    int f=1;
    int l=n;
    while(f<l){
        if(h[f]<h[l]){
            if(s[f]!=s[l]){
                ans+=h[f];
            }
            h[l]-=h[f];
            f++;
        }
        else {
            if(s[f]!=s[l]){
                ans+=h[l];
            }
            h[f]-=h[l];
            l--;
        }
    }
    cout<<ans;
    return 0;
}

