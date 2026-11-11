#include<bits/stdc++.h>
using namespace std;
int n,l,r;
char ch[200005];
long long a[200005],ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    l=1;
    r=n;
    while(l!=r){
        if(ch[l]!=ch[r]){
            if(a[l]>=a[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
            else{
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }
        }
        else{
            if(a[l]>=a[r]){
                a[l]-=a[r];
                r--;
            }
            else{
                a[r]-=a[l];
                l++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
