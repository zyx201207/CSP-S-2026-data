#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n];
    int ans[m+10]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }    
    for(int i=0;i<n;i++){
        int no[n+10]={0};
        int r=0;
        for(int j=i;j<n;j++){
            bool b=1;
            for(int k=0;k<=r;k++){
                if(no[k]==a[j]){
                    r=k;
                    no[k]=a[j];
                    b=0;
                    break;
                }
            }
            if(b){
                r++;
                no[r]=a[j];
            }
        }
        for(int j=0;j<=r;j++){
            ans[no[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
