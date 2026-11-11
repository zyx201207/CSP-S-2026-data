#include<bits/stdc++.h>
using namespace std;
long long arr[200005];
char brr[200005];
int main()
{

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

   // ios::sync_with_stdio(0);// stdin(0), stdout(0);

    int n;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i]>>brr[i];
        //cout<<1;
    }

    long long r=n,l=1;
    while(l<r){

        if(arr[r]==arr[l]){
            if(brr[r]!=brr[l]){
                sum+=arr[r];
                r--;
                l++;
                //cout<<1<<"  "<<sum<<" ";
            }
        }else{
            long long mn=min(arr[r], arr[l]);
            if(brr[r]!=brr[l]){
                sum+=mn;

            }
            arr[r]-=mn;
            arr[l]-=mn;
            if(arr[r]==0){
                r--;
            }else{
                l++;
            }
        }
    }
    cout<<sum;

    return 0;
}
