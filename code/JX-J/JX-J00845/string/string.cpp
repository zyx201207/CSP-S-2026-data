#include <bits/stdc++.h>
using namespace std;
string s[60000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out"."w",stdout);
    int n,cnt=0,start=1;cin>>n;
    for(int i=1;i<=n;i++){
        int num;cin>>num;
        char letter;cin>>letter;
        for(int j=start;j<=start+num-1;j++)
            s[j]=letter;
        start+=num;
    }
    for(int i=1;i<=(start-1)/2;i++){
        if(s[i]!=s[start-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
