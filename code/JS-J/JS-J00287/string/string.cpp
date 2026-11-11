#include<bits/stdc++.h>
using namespace std;
long long n,m,l;
string s,b;
char a;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>m>>a;

        for(int i=1;i<=m;i++){
            s=s+a;
        }
        l+=m;
    }
    long long num=0;

    for(int i=0;i<(l-1)/2;i++){
        if(s[i]!=s[l-i-1]){
            s[i+l-1]=s[i];
            num++;
        }
    }

    cout<<num;
    return 0;
}
