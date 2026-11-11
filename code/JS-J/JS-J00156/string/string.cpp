#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool solve(string s3){
    string s1=s3;
    reverse(s1.begin(),s1.end());
    for(int i=0;i<s3.size();i++){
        if(s3[i]!=s1[i]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        string op;
        cin>>op;
        while(a--){
            s=s+op;
        }
    }
    long long ans=0;
    string s2;
    s2=s;
    reverse(s2.begin(),s2.end());
    for(int i=0;i<s.size();i++){
        if(solve(s)){
            cout<<ans;
            return 0;
        }
        else{
            s[i]=s2[i];
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
