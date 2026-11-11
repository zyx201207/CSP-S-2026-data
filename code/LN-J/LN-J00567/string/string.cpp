#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
char a;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1 ;i<=n;i++){
        cin>>m>>a;
        for(int j=1;j<=m;j++){
            s+=a;
        }
    }
    int t=s.size()/2;
    for(int i=0;i<t;i++){
        int y=s.size()-1-i;
        if(s[i]!=s[y])sum++;
    }
    cout<<sum;
    return 0;
}
