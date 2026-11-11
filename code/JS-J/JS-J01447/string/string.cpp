#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int ans,n=0;
    cin>>ans;
    for(int i=1;i<=ans;i++){
        int x;
        cin>>x;
        n+=x;
        string a;
        cin>>a;
        while(x--){
            s+=a;
        }
    }
    int cnt=0;
    for(int i=0;i<s.size()/2;i++){//n-i-1
        if(s[i]!=s[n-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
