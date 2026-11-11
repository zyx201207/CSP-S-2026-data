#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,m,ans,arr[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
        map<int,int>ma;
        for(int i=1;i<=n;i++){
                cin>>arr[i];
                ma[arr[i]]++;
        }
        sort(arr+1,arr+n+1,greater<int>());
        if(m==1){
            cout<<arr[1]<<endl;
            return 0;
        }else if(m==n){
            int ans=arr[1];
            for(int i=2;i<=n;i++){
                ans&=arr[i];
            }
            cout<<ans<<endl;
            return 0;
        }else if(m==2){
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(ans,arr[i]&arr[j]);
                }
            }
            cout<<ans<<endl;
            return 0;
        }else if(m==n-1){
            int ans=arr[1];
            for(int i=2;i<=n;i++)ans&=arr[i];
            for(int i=1;i<=n;i++){
                if(ma[arr[i]]>1){
                    cout<<ans<<endl;
                    return 0;
                }
            }
            int b=ans,wei=0;
            while(arr[n]){
                if((arr[n]&1)&&(ans&1)){
                    ans-=(int)pow(2,wei);
                }
                b>>=1;
                arr[n]>>=1;
                wei++;
            }
            cout<<ans<<endl;
        }else{
            int ans=arr[1];
            for(int i=2;i<=m;i++)ans&=arr[i];
            cout<<ans<<endl;
        }
    return 0;
}
