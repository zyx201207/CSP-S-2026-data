#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int arr[N],same[N];
bool flag[N];
int ans;
signed main(){
//    freopen("and.in","r",stdin);
//    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    int maxi=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        same[i]=arr[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            if(arr[i]>maxi){
                maxi=arr[i];
            }
        }
        cout<<maxi;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(arr[i]&arr[j]>m&&i!=j){
                    maxi=arr[i]&arr[j];
                }
            }
        }
        cout<<maxi;
    }else if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int k=j;k<=n;k++){
                    if((arr[i]&arr[j]&arr[k])>maxi&&i!=j&&j!=k&&k!=i){
                        maxi=arr[i]&arr[j]&arr[k];
                    }
                }

            }
        }
        cout<<maxi;
    }else if(m==4){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int k=j;k<=n;k++){
                    for(int l=k;l<=n;l++){
                        if((arr[i]&arr[j]&arr[k]&arr[l])>maxi&&i!=j&&j!=k&&k!=i&&l!=i&&l!=j&&l!=k){
                            maxi=arr[i]&arr[j]&arr[k]&arr[l];
                        }
                    }

                }

            }
        }
      cout<<maxi;
    }else if(n==m){
        maxi=arr[1];
        for(int i=2;i<=n;i++){
            maxi=maxi&arr[i];
        }
        cout<<maxi;
    }else{
        cout<<(n+1)/2;
    }
    return 0;

}


