#include<bits/stdc++.h>
using namespace std;
string s;
int n,a;
long long sum;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int l=0;l<a;l++){
            s+=c;
        }
    }
    int l=s.size()-1;
    for(int i=0;i<(s.size()+1)/2;i++){
        if(s[i]!=s[l]){
            sum++;
        }
        l--;
    }
    cout<<sum;
    return 0;
}
