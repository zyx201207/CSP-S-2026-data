#include<bits/stdc++.h>
using namespace std;
int n;
string b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a;
        cin>>c;
        for(int j=1;j<=a;j++){
            b+=c;
        }
    }
    int l=0,r=b.length()-1;
    int ans=0;
    while(l<=r){
        if(l!=r)ans++;
        l++;
        r--;
    }
    cout<<ans;
}

