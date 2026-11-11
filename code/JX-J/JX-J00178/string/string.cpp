#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int a;
char c;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>c;
        for(int j=0;j<a;i++){
            s+c;
        }
    }
    int m=s.size();
    int cnt=0;
    for(int l=0;l<m/2;l++){
        if(s[l]!=s[m-l-1]){
            cnt++;
        }
    }
    cout<<1;
    return 0;
}
