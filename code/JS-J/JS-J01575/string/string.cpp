#include<bits/stdc++.h>
using namespace std;
int n;
long long ss1=0,ss2=0,cnt=0;
struct P{
    int s;
    char ss;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].ss;
        cnt+=a[i].s;
    }
    long long l=0,r=cnt,z1=1,z2=n;
    while(l<r){
        if(a[z1].ss!=a[z2].ss){
            if(a[z1].s<a[z2].s){
                ss1+=a[z1].s;
                l+=a[z1].s;
                r-=a[z1].s;
                a[z2].s-=a[z1].s;
                z1++;
            }
            else{
                ss1+=a[z2].s;
                l+=a[z2].s;
                r-=a[z2].s;
                a[z1].s-=a[z2].s;
                z2--;
                if(a[z1].s==0){
                    z1++;
                }
            }
        }
        else{
            if(a[z1].s<a[z2].s){
                l+=a[z1].s;
                r-=a[z1].s;
                a[z2].s-=a[z1].s;
                z1++;
            }
            else{
                l+=a[z2].s;
                r-=a[z2].s;
                a[z1].s-=a[z2].s;
                z2--;
                if(a[z1].s==0){
                    z1++;
                }
            }
        }
    }
    cout<<ss1;
    return 0;
}
