#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+99;
int n;
int num[10];
char str[10];
string a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(nullptr);
    cin.tie(nullptr);
    // cin.ignore();
    cin>>n;
    //cout<<"n:"<<n<<endl;
    int sum=0;
    bool isbig=0;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i]>>str[i];
        sum+=num[i];
        if(num[i]>=(int)1e7)
        {
            isbig=1;
        }
        
        for(int j=1;j<=num[i];j++)
        {
            a+=str[i];
        }
    }
    int ans=0;
    if(isbig)
    {
        cout<<sum/2;
        return 0;
    }
    for(int i=0;i<=a.size();i++)
    {
        //cout<<a[a.size()-i-1]<<" "<<a[i]<<endl;
        if(a[i]!=a[a.size()-i]){
            ans++;
        }
    }
    cout<<ans/2;
    return 0;
}