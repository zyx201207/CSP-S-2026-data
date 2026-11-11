#include<bits/stdc++.h>;
using namespace std;
string s;
long long m1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[n+10];
    char b[n+10];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
    }
    int x=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=b[i];
        }
    }
    for(int i=0;i<(s.size()/2);i++){
        if(s[i]!=s[s.size()-i-1]){
            m1++;
        }
    }
    cout<<m1;
    return 0;
}

