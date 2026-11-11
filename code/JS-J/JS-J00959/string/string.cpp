#include <bits/stdc++.h>
using namespace std;

const int N=200005;

int a[N];
char c[N];
long long s[N],l,ans;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s[i]=s[i-1]+a[i];
        l+=a[i];
    }

    long long i=1,j=n,p=1;
    while(i<=j){
        if(c[i]!=c[j]){
            ans+=min(a[i],a[j]);
        }

        if(a[i]>a[j]){
            a[i]-=a[j];
            j--;
        }
        else if(a[i]==a[j]){
            i++;
            j--;
        }
        else{
            a[j]-=a[i];
            i++;
        }
    }

    cout<<ans<<endl;
    return 0;
}