#include<bits/stdc++.h>
using namespace std;
int n,ln,rn;
long long ans;
char lc,rc;
pair<int,char> a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    int l=0,r=n-1;
    ln=a[0].first;
    rn=a[n-1].first;
    lc=a[0].second;
    rc=a[n-1].second;
    while(l<r){
        if(lc==rc){
            if(ln==rn){
                ln=a[++l].first;
                lc=a[l].second;
                rn=a[--r].first;
                rc=a[r].second;
            }
            else if(ln>rn){
                ln-=rn;
                rn=a[--r].first;
                rc=a[r].second;
            }
            else {
                rn-=ln;
                ln=a[++l].first;
                lc=a[l].second;
            }
        }
        else{
            if(ln==rn){
                ans+=ln;
                ln=a[++l].first;
                lc=a[l].second;
                rn=a[--r].first;
                rc=a[r].second;
            }
            else if(ln>rn){
                ans+=rn;
                ln-=rn;
                rn=a[--r].first;
                rc=a[r].second;
            }
            else {
                ans+=ln;
                rn-=ln;
                ln=a[++l].first;
                lc=a[l].second;
            }
        }
    }
    cout<<ans;
    return 0;
}
