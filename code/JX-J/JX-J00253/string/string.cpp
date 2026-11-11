#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        for(int j=1;j<=x;j++){
            s+=y;
        }
    }
    int cnt=0;
    int r=0,l=s.size()-1;
    while(r<l){
        if(s[r]!=s[l]){
            s[r]=s[l];
            cnt++;
        }
        r++;
        l--;
    }
    cout<<cnt;
    return 0;
}
