#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int a,wt=0;
char c;
string s=" ";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //ios::sync_with_stdio(nullptr);
    //cin.tie(0);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        ans+=a;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    for(int i=1;i<=ans;i++){
        if(s[i]!=s[ans+1-i]){
            s[i]=s[ans+1-i];
            wt++;
        }
    }
    cout<<wt;
    return 0;
}
