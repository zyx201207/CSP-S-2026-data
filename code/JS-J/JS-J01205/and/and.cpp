#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=-1000;
int a[100100];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-m;i++){
        int sum=a[i];
        for(int j=i+1;j<n-m;j++){



            for(int k=j;k<j+m-1;k++){
                if(k>=n){
                    break;
                }
                sum=sum&a[k];
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;


    return 0;

}
