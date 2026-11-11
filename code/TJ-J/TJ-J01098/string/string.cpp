#include<iostream>
#include<string>
using namespace std;
int a[200005],n,ans;
char w[200005];
string aa="";
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            aa+=w[i];
        }
    }
    for(int i=1;i<=aa.length()/2;i++){
        if (int(aa[i-1])!=int(aa[aa.length()-i])){
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
