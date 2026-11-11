#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,cnt=0;
    string a;
    cin>>n;
    for(int i=0;i<n;i++){
        int w;
        string x;
        cin>>w>>x;
        for(int j=0;j<w;j++){
            a+=x;
        }
    }
    for(int i=0;i<(a.size()/2);i++){
        if(a[i]!=a[a.size()-1-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
