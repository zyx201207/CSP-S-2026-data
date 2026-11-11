#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,num=0,y;
    string b;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    for(int j=n-1;j>-1;j--){
        if(a[j]/2==1){
            b[j]=1;
        }
        if(a[j]/2==0){
            b[j]=0;
        }
        else{
            b[j]=a[j]%2;
        }
    }
        a[i]=b;
}
    if(m=1){
        for(int i=0;i<n;i++){
                y=a[i];
            if(y>num){
                num=y;
            }
        }
    }
    if(m=2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                    y=a[i]&a[j];
                if(y>num){
                    num=y;
                }
            }
    }
    }
    cout<<num;
    return 0;
    }
