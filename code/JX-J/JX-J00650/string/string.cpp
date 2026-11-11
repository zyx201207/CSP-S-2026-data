#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a[20005];
    string b[20005];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long cnt=0;
    int l=1;
    int r=n;
    while(l<r){
        if(b[l]==b[r]){
            if(a[l]==a[r]){
                l++;
                r--;
            }else{
                if(a[l]<a[r]){
                    a[r]-=a[l];
                    l++;
                }else{
                    a[l]-=a[r];
                    r--;
                }
            }
        }else{
            cnt+=min(a[l],a[r]);
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }else if(a[l]==a[r]){
                l++;
                r--;
            }else{
                a[l]-=a[r];
                r--;
            }
        }
    }
    cout<<cnt;
}
