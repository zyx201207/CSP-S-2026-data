#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a[200005];
    string c;
    long long n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    long long l=0,r=s.size()-1;
    long long ans=0;
    while(l<=r){
        if(s[l]==s[r]){
            l++;
            r--;
        }else{
            ans++;
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
