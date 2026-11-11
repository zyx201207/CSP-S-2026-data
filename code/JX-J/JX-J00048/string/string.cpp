#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a;
    unsigned long long asize = 0;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;asize+=tmp;
        char c;cin>>c;
        for(int j=0;j<tmp;j++){
            a.push_back(c);
        }
    }
    unsigned long long ans=0;
    for(unsigned long long i=0;i<asize/2;i++){
        if(a[i]!=a[asize-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
