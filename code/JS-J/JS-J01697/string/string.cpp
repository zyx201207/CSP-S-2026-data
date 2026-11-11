#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int i=1,j=n;
    while(i<j){
        if(b[i]==b[j]){
            if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }
            else if(a[i]<a[j]){
                a[j]-=a[i];
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        else{
            if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                j--;
            }
            else if(a[i]<a[j]){
                ans+=a[i];
                a[j]-=a[i];
                i++;
            }
            else{
                ans+=a[i];
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
