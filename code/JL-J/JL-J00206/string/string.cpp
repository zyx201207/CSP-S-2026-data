#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long n,a[200005],num=0,lsn=0,cnt=0;
    char e[200005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>e[i];
        cnt+=a[i];
    }
    cnt/=2.0+0.5;
    int cnt_=cnt;
    int i=0;
    while(cnt==0){
        if(cnt_>=a[i]){
            cnt_-=a[i];
            i++;
        }
        else{
            a[i]-=cnt;
            cnt=0;
        }
    }
    int j=0,k=0;

    while(j<=n){
        bool flag=true;
        for(int h=0;h<n;h++){
            if(a[h]!=0) flag=false;
        }
        if(flag){
            cout<<num;
            break;
        }
        if(a[j]==0) j++;
        if(a[n-k-1]==0) k++;
        if(e[j]==e[n-k-1]){
            if(a[n-k-1]>a[j]){
                a[n-k-1]-=a[j];
                a[j]=0;
                continue;
            }
            else{
                a[j]-=a[n-k-1];
                a[n-k-1]=0;
                continue;
            }
        }
        else{
            if(a[n-k-1]>a[j]){
                lsn=a[n-k-1];
                a[n-k-1]-=a[j];
                num+=lsn-a[n-k-1];
                a[j]=0;
                continue;
            }
            else{
                lsn=a[j];
                a[j]-=a[n-k-1];
                num+=lsn-a[j];
                a[n-k-1]=0;
                continue;
        }
    }}
    return 0;
}
