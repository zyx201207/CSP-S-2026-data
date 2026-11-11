#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)s[cnt++]=c;
    }
    for(int i=0;i<cnt/2;i++){
        if(s[i]!=s[n-i])sum++;
    }
    cout<<sum;
    return 0;
}
