#include<bits/stdc++.h>
using namespace std;
long long n,m,arr[100005],tot,minn=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
//    cout<<n<<m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
//        cout<<arr[i];
    }
    sort(arr+1,arr+1+n);
    tot=m;
    for(int i=1;i<n;i++){
        if((i-minn)*(arr[i+1]-arr[i])<=tot) tot-=(i-minn)*(arr[i+1]-arr[i]);
        else if(arr[minn]-arr[i+1]+(i-minn-1)*(arr[i+1]-arr[i])<=tot){
            tot-=arr[minn]-arr[i+1]+(i-minn-1)*(arr[i+1]-arr[i]);
            minn++;
        }
        else{
            cout<<i+1-minn;
            return 0;
        }
    }
    cout<<n+1-minn;
}
