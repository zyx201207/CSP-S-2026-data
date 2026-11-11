#include<bits/stdc++.h>
using namespace std;
long long ans;
vector<int> a;
vector<char> b;
long long l;
int main(){
   freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long p=n;
    a.resize(n+1);
    b.resize(n+1);
    for(long i=1;i<=n;i++){
        cin>>a[i];
        l+=a[i];
        cin>>b[i];

    }
    long long t=1;
    long long i=1;
    while(i<=l/2){
        char c,d;
        c=b[t];
        d=b[p];
        i+=min(a[t],a[p]);
        // if(f-i-a[t]>=0&&f-i-a[p]>=0){
            if(c!=d){
            ans+=min(a[t],a[p]);
            if(a[t]>a[p]){
                a[t]-=min(a[t],a[p]);
            a[p]-=min(a[t],a[p]);
                p--;
            }else if(a[p]>a[t]){
                a[t]-=min(a[t],a[p]);
            a[p]-=min(a[t],a[p]);
                t++;
            }else{
            a[t]-=min(a[t],a[p]);
            a[p]-=min(a[t],a[p]);
            }

        }else{

            if(a[t]>a[p]){
                a[t]-=min(a[t],a[p]);
            a[p]-=min(a[t],a[p]);
                p--;
            }else if(a[p]>a[t]){
                a[t]-=min(a[t],a[p]);
            a[p]-=min(a[t],a[p]);
                t++;
            }else{
            a[t]-=min(a[t],a[p]);
            a[p]-=min(a[t],a[p]);
            }
        }

    }


    cout<<ans;
    return 0;
}
