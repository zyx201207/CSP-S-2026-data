#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s1;
    for(int i=1;i<=n;i++){
        int x;
        string s;
        cin>>x>>s;
        for(int j=1;j<=x;j++){
            s1+=s;
        }
    }
    string s2=s1;
    string s3=s2;
    long long cnt=0;
    for(int i=0;i<=s2.size()-1;i++){
        if(s3[i]!=s2[s2.size()-1-i]){
            cnt++;
        }
    }
    cout<<cnt/2;
    return 0;
}
