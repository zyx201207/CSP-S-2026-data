#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m,ans=0;
    cin>>n>>m;
    int a[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int temp;
        for(int j=n;j>=i;j--){
            if(a[j]==a[i]){
                temp=j+1;
                break;
            }
        }
        int flag=0;
        for(int j=i;j<temp;j++){
            for(int k=temp;k<=n;k++){
                if(a[k]==a[j]){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0) ans++;
    }
    cout<<m<<' '<<m<<' '<<m;
    return 0;
}
