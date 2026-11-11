#include <iostream>
#include <algorithm>
using namespace std;
const int N=2e5;
string a;
int b[N];
void in(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
}
int main(){
    in();
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        string s;
        cin>>s;
        for(int i=0;i<x;i++){
            a+=s;
        }
    }
    for(int i=0;i<a.size();i++){
        b[i]=a[i]-'a';
    }
    sort(b,b+a.size());
    int ans=2e9;
    do{
        bool ok=true;
    for(int i=0;i<a.size();i++){
        int j=a.size()-i-1;
        if(b[i]!=b[j]) ok=0;
    }
        if(ok){
            int cnt=0;
            for(int i=0;i<a.size();i++){
                if(a[i]-'a'!=b[i]){
                    cnt++;
                }
            }
            ans=min(ans,cnt);
        }
    }
    while(next_permutation(b,b+a.size()));
    cout<<ans;
    return 0;
}
