#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=n,j=1;
    while(j<i)
    {
        if(a[j]>a[i]){
            if(c[j]!=c[i]){
                ans+=a[i];
            }
            a[j]-=a[i];
            i--;
        }
        else if(a[j]==a[i]){
            if(c[j]!=c[i]){
                ans+=a[j];
            }
            j++;
            i--;
        }else{
            if(c[j]!=c[i]){
                ans+=a[j];
            }
            a[i]-=a[j];
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
