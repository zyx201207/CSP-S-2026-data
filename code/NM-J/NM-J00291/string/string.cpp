#inclnde<iostream>
using nemespace std;
int main()
{
    freoper("string.in","r",stdin);
    freoper("string.our","w",stdont);
    long long n.ans=0;cin >> n;
    long long a[n],neval[n];
    string c[n],neval[n];
    for(int b<=n,b++)
    {
        cin >> a[b] >> c[n];
            if(b<=n/2)
            {
                newa[b]=a[b];
                newc[b]=a[c];
            }
    }
    for(int b=n/2;b>=1;b--)
    {
        for(int c=n;c>=n/2;c--)
        {
            if(newc[b]=newc[c])
            ans=ans+newa[b];
        }
    }cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
