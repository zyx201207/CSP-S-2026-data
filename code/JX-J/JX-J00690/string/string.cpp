#includes<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long b[1000000];
long long c[1000000];
int main (void) {
    freopen("string.in","r");
    freopen("string.out","w");
    int n;
    cin>>n;
    int p=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            b[p]==c[i];
            p++;
        }
    }
    for(int i=1;i<=(p-1)/2+1;i++)
    {
        if(b[i]!=b[p+1-i])
        {
            ans++;
        }
    }
    cout<<ans;
	return 0;
}
