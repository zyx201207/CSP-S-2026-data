#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        string c;
        cin>>a;
        cin>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    int sum=s.size();
    int cnt=0;
    for(int i=1;i<=sum/2;i++){
        if(s[i]!=s[sum-i+1]) cnt++;
    }
    cout<<cnt-1;
    return 0;
}
