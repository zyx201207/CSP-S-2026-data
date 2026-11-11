#include <bits/stdc++.h>
using namespace std;
int a[300005],ans[300005];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int num=a[i];
            if(num==a[j] && a[j]!=0){
                a[i]=0;
            }
        }
        ans[i]+=1;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
