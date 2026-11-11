#include<bits/stdc++.h>
using namespace std;
char arr[10000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=0;cin>>n;
    long long num=0;
    for(int i=0;i<n;i++){
        int x=0;char a;
        cin>>x>>a;
        while(x--){
            arr[num]=a;
            num++;
        }
    }
    long long ans=0;
    for(int i=0;i<num/2;i++){
        if(arr[i]!=arr[num-i-1]){
            arr[i]=arr[num-i-1];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
