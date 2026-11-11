#include<bits/stdc++.h>
using namespace std;
int n,m,last=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        }
    for(int i=a[1];i<=a[n];i++){
        int sum=0,num=0;
        for(int j=1;j<=n;j++){
            b[j]=i-a[j];
            if(b[j]>=0){
                sum=sum+b[j];
                num++;
                }
            }
        if(sum>m){
            cout<<last;
            return 0;
            }
        last=num;
    }
    return 0;
}
