#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(m==1){
        int maxx=arr[0];
        for(int i=1;i<=n;i++){
            if(arr[i]>maxx)maxx=arr[i];
        }
        cout<<maxx;
    }
    else if(m==n&&n>1){
        int value=arr[1];
        for(int i=2;i<=n;i++){
            value&=arr[i];
        }
        cout<<value;
    }
    else if(m==n-1&&n>2){
        int minn=arr[1];
        for(int i=2;i<=n;i++){
            if(arr[i]<minn)minn=arr[i];
        }
        swap(minn,arr[1]);
        int value=arr[2];
        for(int i=3;i<=n;i++){
            value&=arr[i];
        }
        cout<<value;
    }
    else if(m==2){
        sort(arr.begin(),arr.end());
        int micha=arr[n]-arr[n-1];
        int fir=n;
        for(int i=n-1;i>=1;i--){
            if(arr[i]-arr[i-1]<micha){
                micha=arr[i]-arr[i-1];
                fir=i;
            }
        }
        int va=arr[fir]&arr[fir-1];
        cout<<va;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
