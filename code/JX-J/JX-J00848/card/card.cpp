#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],p,i=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    p=n;
    while(p--){
        int table[10005]
        for(int j=i;j<=n;j++){
            int d=a[j],y=1;
            bool flag=1;
            for(int x=i;x<j;x++){
                if(a[x]==d){
                    flag=0;
                }
            }
            if(flag)table[y+1]=d;
            else{
                for(int k=y+1;k<j;k++)table[k]=0;
            }
       }
    }
    return 0;
}
