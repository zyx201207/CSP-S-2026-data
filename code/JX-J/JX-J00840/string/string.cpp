#include <bits/stdc++.h>
using namespace std;
int a[10000];
char b[10000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];j++){
            s+=b[i];
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
                sum++;
        }
    }
    cout<<sum;
    return 0;
}
