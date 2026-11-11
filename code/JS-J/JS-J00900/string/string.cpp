#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sum=0,a[200005];
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>s[i];
        sum+=a[i];
    }
    long long num=sum;
    if(sum%2==0)sum=sum/2-1;
    else sum=(sum+1)/2-1;
    int i=0,j=n-1;
    long long ans=0;
    while(num>sum)
    {
        if(a[i]==a[j]&&s[i]==s[j]){
            num-=a[j];
            i++;j--;
        }
        else if(a[i]!=a[j]&&s[i]==s[j]){
            ans+=abs(a[i]-a[j]);
            num-=max(a[i],a[j]);
            if(num<=sum)ans-=(sum-num+1);

            if(a[i]>a[j]){
                a[j-1]-=abs(a[i]-a[j]);
            }
            else{
                a[i+1]-=abs(a[i]-a[j]);
            }
        i++;j--;
        }
        else if(a[i]==a[j]&&s[i]!=s[j]){
            ans+=a[i];
            num-=a[j];
            if(num<=sum)ans-=(sum-num+1);
            i++;j--;
        }
        else{
                ans+=max(a[i],a[j]);

                num-=max(a[i],a[j]);
                 if(num<=sum)ans-=(sum-num+1);
                if(a[i]>a[j]){
                a[j-1]-=abs(a[i]-a[j]);
            }
            else{
                a[i+1]-=abs(a[i]-a[j]);
            }
            i++;j--;
        }
    }
    cout<<ans;
}
