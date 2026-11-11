#include<bits/stdc++.h>
#define N 2000000100
using namespace std;

char s[N];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,j;
    long long ans=0,l=1;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s[l]=c;
            l++;
        }
    }
    l--;
    for(long long i=1;i<=(l+1)/2;i++){
       ans+=(s[i]!=s[l+1-i]);

    }
    cout<<ans;
    return 0;




}