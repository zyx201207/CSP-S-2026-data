#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int q[5000];
    cin>>n>>m;
    int a[5000];
    for (int i =0;i<5000;i++){
            q[i]=0;
    }
    for (int i =0;i<n;i++){
        int q;
        cin>>q;
        a[i]=q;
    }
    int b[3000];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]=a[j]){
                for (int s=i;s<=j;s++)q[i]-=1;
            }
        }
        for (int j=i;j<n;j++){
            if(q[j]==0){
                b[i]=b[i]+1;
            }
        }
        for (int i =0;i<5000;i++){
            q[i]=0;
        }
    }
    for (int i=0;i<m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
