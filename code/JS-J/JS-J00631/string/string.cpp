#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int i=1,j=n;
    while(i<j){
        ans+=(c[i]==c[j]?0:max(a[i],a[j]));
        if(a[i]>a[j]){
            a[i]-=a[j];
            j--;
        }
        if(a[i]<a[j]){
            a[j]-=a[i];
            i++;
        }
        else i++,j--;
    }
    cout<<ans;
    return 0;
}
