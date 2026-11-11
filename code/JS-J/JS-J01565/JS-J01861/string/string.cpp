#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+10;
int n,a[N];
ll ans;
char b[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }

    int l=1,r=n;
    while(r>l){
        if(b[l]==b[r]){
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else{
                a[l]-=a[r];
                r--;
            }
        }
        else{
            if(a[l]<a[r]){
                a[r]-=a[l];
                ans+=a[l];
                l++;
            }
            else{
                a[l]-=a[r];
                ans+=a[r];
                r--;
            }
        }
    }

    cout<<ans;

    return 0;
}
