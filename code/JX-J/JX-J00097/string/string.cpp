#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int x,y;
long long ans;
long long mid;
long long ne;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        mid+=a[i];
    }
    mid=mid>>1;
    x=1;
    y=n;
    for(int i=1;i<=n;i++){
            if(ne+min(a[x],a[y])>mid){
                if(c[x]!=c[y]){
                    ans+=(mid-ne);
                }
                break;
            }
            ne+=min(a[x],a[y]);
            if(c[x]!=c[y]){
                ans+=min(a[x],a[y]);
            }
            if(a[x]>a[y]){
                a[x]-=a[y];
                y--;
            }
            else if(a[x]<a[y]){
                a[y]-=a[x];
                x++;
            }
            else{
                x++;
                y--;
            }
    }
    cout<<ans;
    return 0;
}
