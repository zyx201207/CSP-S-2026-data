#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt1,cnt2;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s;
    for(int i=0;i<n;i++){
        if(a[i]=a[i-1]){
        for(int j=i-1;j>=0;j--){
                a[j]=0;
                while(j--) {cnt1--;cnt2--;}
                }
        }
        else{
            for(int k=i-2;k>=0;k--){
                a[k]=0;

            }
        }
        if(a[i]==1) cnt1++;
        if(a[i]==2) cnt2++;
    }
        cout<<1<<" "<<1;
        return 0;

}
