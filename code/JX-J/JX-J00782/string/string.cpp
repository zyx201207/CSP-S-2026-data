#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=0,r=n+1;
    long long l_len=0,r_len=0;
    long long i=0,sum=0;

    while(1){
        if(l==n&&r==1){
            break;
        }
        if(l_len==r_len){
            l_len+=a[++l];
            r_len+=a[--r];

            i=min(l_len,r_len);
            if(c[l]!=c[r])sum+=min(a[l],a[r]);
            continue;
        }
        if(l_len>r_len){
            int z=r_len;
            r_len+=a[--r];

            i+=min(l_len,r_len)-z;
            if(c[l]!=c[r])sum+=min(l_len,r_len)-z;
            continue;
        }
        if(l_len<r_len){
            int z=l_len;
            l_len+=a[++l];

            i+=min(l_len,r_len)-z;
            if(c[l]!=c[r])sum+=min(l_len,r_len)-z;
            continue;
        }




    }
    cout<<sum/2<<'\n';
    return 0;
}
