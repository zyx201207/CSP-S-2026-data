include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<a[n];
    return 0;
}
