#include<bits/stdc++.h>
using namespace std;
struct t{
    char x;
    long long num;
}arr[200005];
long long l=1,r=0;
long long n;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        r++;
        cin>>arr[i].num>>arr[i].x;
    }
    while(l<=r){
        if(arr[l].x==arr[r].x){
            if(arr[l].num>arr[r].num){
                arr[l].num-=arr[r].num;
                r--;
            }else{
                arr[r].num-=arr[l].num;
                l++;
            }
        }else{
            if(arr[l].num>arr[r].num){
                ans+=arr[r].num;
                arr[l].num-=arr[r].num;
                r--;
            }else{
                ans+=arr[l].num;
                arr[r].num-=arr[l].num;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
