#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    long long n,m;
    cin>>n>>m;
    long long *a =new long long[n+64];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //n(n-1)=2*m
    //n^2-n-2*m=0
    long long temp=1+8*m;
    long long sub=a[1]-a[0];
    cout<<(long long)((sub+sqrt(sub*sub+8*m*sub))/(2*sub)-1)<<endl;
    delete[] a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
