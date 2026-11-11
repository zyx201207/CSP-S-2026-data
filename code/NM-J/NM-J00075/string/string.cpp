#include <bits/stdc++.h>
using namespace std;

char s[1000000000],s_[1000000000],c;
long long n,a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int cnt=1,l=0;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s[cnt]=c;
            cnt++;
            l++;
        }
    }
    cnt=1;
    for(int i=l;i>=1;i--){
        s_[cnt]=s[i];
        cnt++;
    }
    int num=0;
    for(int i=1;i<=l/2;i++){
        if(s_[i]!=s[i]){
            num++;
        }
    }
    cout<<num;
    return 0;
}
