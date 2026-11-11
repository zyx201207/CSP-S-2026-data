#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    long long cnt=0;
    string s;
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            s.push_back(c[i]);
        }
    }
    int z=s.size();
    if(z%2==0){
        z=z/2;
    }else{
        z=z/2+1;
    }
    for(int i=0;i+z<s.size();i++){
        if(s[i]!=s[i+z])cnt++;
    }
    cout<<cnt;
    return 0;
}
