#include<iostream>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int q=0;q<t;q++)
    {
        int n,d;
        cin>>n>>d;
        int a[n];
        for(int w=0;w<n;w++)
        {
            cin>>a[w];
        }
        int cha=a[2]-a[1];
        int ans=0;
        for(int geshu=3;geshu<=n;geshu++)
        {
            if(((geshu-1)*cha)%d!=0 && (geshu-1)*cha>d)
            {
                ans+=n-geshu+1;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
