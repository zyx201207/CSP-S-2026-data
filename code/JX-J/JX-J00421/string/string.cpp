#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,cnt;
char s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    string a="";
    string b="";
    for(int i=1;i<=n;i++){
        cin>>cnt;
        cin>>s;
        for(int i=1;i<=cnt;i++){
            a+=s;
        }
    }
    for(int i=a.size()-1;i>=0;i--){
        b+=a[i];
    }
    int sum=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            sum++;
        }
    }cout<<sum/2;
    return 0;
}








