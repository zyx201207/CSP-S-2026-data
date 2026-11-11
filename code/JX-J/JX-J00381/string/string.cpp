#include<bits/stdc++.h>
using namespace std;
long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        string c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s+=c;
        }
    }
    long long len=s.size();
    int l=0,r=len-1;
    while(l<r){
        if(s[l]!=s[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout<<cnt;
    return 0;
}
