#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,a,i,j;
    char c;
    cin>>n;
    string s;
    for(i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s.push_back(c);
        }
    }
    int ans=0;
    j=s.size()-1;
    for(i=0;i<=(s.size()-1)/2;i++){
        if(s[i]!=s[j]){
            ans++;
        }
        j--;
    }
    cout<<ans;
    return 0;
}
