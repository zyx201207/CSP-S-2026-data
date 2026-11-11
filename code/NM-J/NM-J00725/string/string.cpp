#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0,mid,ans=0;
    long long a;
    string s,L;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a>>s;
        cnt+=a;
        for(int j=1;j<=a;j++){
            L+=s;
        }
    }
    if(cnt%2==0){
         mid=cnt/2;
         for(int i=mid,j=mid+1;i>=0;i--,j++){
                if(L[i-1]!=L[j-1]){
                ans++;
        }
    }
    }else{
         mid=cnt/2+1;
         for(int i=mid-1,j=mid+1;i>=0;i--,j++){
                if(L[i-1]!=L[j-1]){
                ans++;
                }
         }
    }
    cout<<ans;
    return 0;
}
