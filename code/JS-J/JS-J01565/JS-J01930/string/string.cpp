#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long a[200001];
    long long l=0,ans=0;
    char c[200001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    int i=0,j=n-1;
    while(l>0){
        l-=2*min(a[i],a[j]);
        if(c[i]!=c[j]) ans+=min(a[i],a[j]);
        if(a[i]>=a[j]){
            a[i]-=a[j];
            a[j]=0;
            j--;
        }
        else{
            a[j]-=a[i];
            a[i]=0;
            i++;
        }
    }
    cout<<ans;
    return 0;
}
