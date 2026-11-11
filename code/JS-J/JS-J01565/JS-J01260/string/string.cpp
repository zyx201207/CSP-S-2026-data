#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    long long sum=0;
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        sum+=m;
        string c;
        cin>>c;
        for(int j=1;j<=m;j++){
            s+=c;
        }
    }long long cnt=0;
    for(long long i=0;i<sum/2;i++){
        if(s[i]!=s[sum-i-1]){
            cnt++;
        }

    }cout<<cnt;
    return 0;

}
