#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; ++i){
        int k;
        string a;
        cin>>k>>a;
        for(int i=1; i<=k; ++i){
            s+=a;
        }
    }
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]==s[j]){
            i++,j--;
        }
        else{
            i++,j--;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
