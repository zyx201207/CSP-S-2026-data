#include<bits/stdc++.h>
using namespace std;
long long n,m;
int arr[500005];
long long ans=-1;
int bbb[500005];
int kkk[500005];
bool tfa=1;
long long sum;
long long arr1[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(m>1e9){
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if((arr[i]!=i)&&tfa==1)tfa=0;
        }
        if(tfa){
            sum=1;
            for(int i=1;i<n&&(m-i)>0;i++){
                m-=i;
                sum++;
            }
            cout<<sum;
            return 0;
        }
        else {
            cout<<0;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>=0){
            bbb[arr[i]]++;
        }
        else{
            long long f=0-arr[i];
            kkk[f]++;
        }
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        long long rot=arr[i];
        long long k=m;
        int l=i-1;
        if(arr[i]>=0){
           sum=bbb[arr[i]];
        }
        else{
            long long f=abs(arr[i]);
            sum=kkk[f];
        }
        while(k>0){
            if(l<0){
                break;
            }
            if(arr[l]==rot){
                    l--;
                    continue;
            }
            if((k-(rot-arr[l]))>=0){
                k-=(rot-arr[l]);
                l--;
                sum++;
                continue;
            }
            break;
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}//Xenth
//再见c++
