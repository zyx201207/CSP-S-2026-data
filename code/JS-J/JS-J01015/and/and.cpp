#include<bits/stdc++.h>
using namespace std;

int arr[200005];


bool mycmp(int a , int b){
    if(a != b) return a > b;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);


    int n , m;
    cin>>n>>m;

    for(int i=1 ; i<=n ; ++i){
        cin>>arr[i];
    }

    sort(arr+1 , arr+n+1 , mycmp);

    int k=1;
    int maxv = 0;
    for(int i=1 ; i<=n ; ++i){
        if(arr[i] == arr[i-1] && maxv < arr[i]){
            k++;
            maxv = arr[i];
        }
    }

    if(k >= m){
        cout<<maxv;
    }else{
        int ans = arr[1];
        for(int i=2 ; i<=m ; ++i){
            ans &= arr[i];
        }
        cout<<ans;
    }
    return 0;
}
