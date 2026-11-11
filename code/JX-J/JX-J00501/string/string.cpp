#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long l=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        l+=a[i];
    }
    long long i=1,j=l;
    long long as=1,bs=n;
    long long c1=0,c2=0;
    long long ans=0;
    while(i<=j){
        int m=min(a[as],a[bs]);
        if(i+m>j-m){
            int l=i,r=j;
            int mid=(l+r)/2;
            while(l<=r){
                mid=(l+r)/2;
                if(i+mid>j-mid){
                    r=mid-1;
                }
                else if(l+mid<=j-mid){
                    l=mid+1;
                }
            }
            m=mid;
        }
        if(b[as]!=b[bs]){
            ans+=m;
        }
        i+=m;
        j-=m;
        c1+=m;
        c2+=m;
        if(c1>=a[as]){
            as++;
            c1=0;
        }
        if(c2>=a[bs]){
            bs--;
            c2=0;
        }
        a[as]-=c1;
        a[bs]-=c2;
    }
    cout<<ans;
    return 0;
}
