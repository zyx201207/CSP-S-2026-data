#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int bg=1;
    int ed=n;
    long long ans=0;
    while(bg<ed){
        if(b[bg]!=b[ed]){
            if(a[bg]==a[ed]){
                ans+=a[bg];
                b[ed]=b[bg];
                a[bg]=0;
                a[ed]=0;
                ed--;
                bg++;
            }
            if(a[bg]>a[ed]){
                ans+=a[ed];
                b[ed]=b[bg];
                a[bg]-=a[ed];
                a[ed]=0;
                ed--;
            }
            else{
                ans+=a[bg];
                b[bg]=b[ed];
                a[ed]-=a[bg];
                a[bg]=0;
                bg++;
            }
        }
        else{
            if(a[bg]==a[ed]){
                a[bg]=0;
                a[ed]=0;
                ed--;
                bg++;
            }
            if(a[bg]>a[ed]){
                a[bg]-=a[ed];
                a[ed]=0;
                ed--;
            }
            else{
                a[ed]-=a[bg];
                a[bg]=0;
                bg++;
            }
        }
    }
    cout<<ans;
    return 0;
}
