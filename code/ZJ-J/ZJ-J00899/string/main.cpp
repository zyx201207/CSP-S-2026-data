#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<char> c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    a.resize(n+1);
    c.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    long long ans=0;
    while(l<r){
        if(a[l]==0) l++;
        if(a[r]==0) r--;
        int g=r,s=l;
        if(a[l]>a[r]) g=l,s=r;
        a[g]-=a[s];
        if(c[l]!=c[r]) ans+=a[s];
        a[s]=0;


    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
