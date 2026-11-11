#include<iosteam>
using namespace std;
int a[1005};
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int j=1;j<=m;j++)
    {
        if(a[i]<a[i+1])
        {
            a[i]++;
        }
    }
    cout<<a[i];
        
    return 0;
}
