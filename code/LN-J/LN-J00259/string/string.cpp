#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,times;
    string s1;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>times>>s[i];
        for(int j=0;j<times;j++){
            s1+=s[i];
        }
    }
    int l=0,r=s1.size()-1,cnt=0;
    while(l<r){
        if(s1[l]!=s1[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout<<cnt<<endl;
    return 0;
}
