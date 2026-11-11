#include<bits/stdc++.h>
using namespace::std;
int n,ans;
const int N=200005;
int a[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i <=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l <=r)
    {
        if(c[l] != c[r]){
            if(a[l] > a[r])
            {
                ans +=a[r];
                r--;
                a[l]-=a[r+1];
            }
            else{
                ans +=a[l];
                l++;
                if(a[l]==a[r])  r--;
                else a[r]-=a[l-1];
            }
        }
    }
    cout <<ans;
    return 0;
}
