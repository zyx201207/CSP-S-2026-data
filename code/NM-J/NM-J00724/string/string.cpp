#include<bits/stdc++.h>
using namespace std;
vector<string> s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        string b;
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            s.push_back(b);
        }
    }
    int l=s.size();
    for(int i=1;i<=l/2;i++){
        if(s[i]!=s[l-i+1]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
