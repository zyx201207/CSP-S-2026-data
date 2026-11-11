#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int num=0,x,sum=0,s=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        x=a[i];
        for(int i=1;i<=n;i++){
            if(a[i]<x){
                sum+=x-a[i];
                if(sum>m){
                    break;
                }
                else if(sum==m){
                    num++;
                    break;
                }
                num++;
            }
            else if(a[i]==x){
                num++;
            }
        }
        if(s<=num){
            s=num;
        }
        num=0;

    }
    cout<<s;
    return 0;
}
