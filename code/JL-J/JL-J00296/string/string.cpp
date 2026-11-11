#include<bits/stdc++.h>
using namespace std;
int n,num,ans=0;
string ccc;
string a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num;
        cin>>ccc;
        for(int j=1;j<=num;j++){
            a+=ccc;
        }
    }
    for(int i=0;i<=a.length()/2-1;i++){
        if(a[i]!=a[a.length()-i-1]){
            ans++;
            a[a.length()-i-1]=a[i];
        }
    }
    cout<<ans;
    return 0;
}
