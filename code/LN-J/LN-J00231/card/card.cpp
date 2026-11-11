#include<bits/stdc++.h>
using namespace std;
long long m=0,n=0,card[1000000]={},c[1000000]={},t[1000000]={};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>m>>n;
    for(int i=0;i<n;i++)cin>>card[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)t[j]=0;
        int cnt=0,cntt=0;
        for(int j=0;j<n;j++)c[i]=card[i];
        for(int j=i;j<n;j++){
            bool flag=0;
            for(int k=0;k<cnt;k++){
                if(t[k]==c[j])flag=1;
            }
            if(!flag)t[cnt]=c[j];
            else{
                for(int k=j+1;t[k+1];k++)t[k]=0;
            }
        }
        for(int j=0;j<cnt;j++){
            if(t[j]==i)cntt++;
        }
        cout<<cntt;
    }
    return 0;
}
