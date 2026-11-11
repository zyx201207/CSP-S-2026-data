#includes<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main (void) {
    freopen("and.in","r");
    freopen("and.out","w");
    int n,m,p=0;
    cin>>n>>m;
    int da=-900000;
    for(int j=1;j<=m;j++)
    {
    a[p]=0;
    da=-90000;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(da<a[i])
            da=a[i];p=i;
    }
    }
    cout<<da;
	return 0;
}

