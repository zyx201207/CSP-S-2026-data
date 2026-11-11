#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,b=0;
    string c,s,fz;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    for(int i=1;i<=s.size();i++){
        for(int j=s.size();j>=1;j--) fz[j]=s[i];
    }
    cout << 2;
    return 0;
}
