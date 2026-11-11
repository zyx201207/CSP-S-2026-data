#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0,cnt=0;
    string s="";
    cin>>n;
    while(n--){
        int x;char c;
        cin>>x>>c;
        for(int i=1;i<=x;i++){
            s=s+c;
        }
        sum+=x;
    }
    for(int i=sum/2;i<sum;i++){
        if(s[i]!=s[sum-1-i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
