#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    int w=0;
    for(int i=1;i<=n;i++){
        int a;
        string o;
        cin>>a>>o;
        w+=a;
        for(int i=1;i<=a;i++){
            s+=o;
        }
    }
    int l=0,r=w-1,cnt=0;
    while(l<=r){
        if(s[l]==s[r]){
            l++;
            r--;
        }
        else{
            cnt++;
            l++;
            r--;
        }
    }
    cout<<cnt;
    return 0;
}
