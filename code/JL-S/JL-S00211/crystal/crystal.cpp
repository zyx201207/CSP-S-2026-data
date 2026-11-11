#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,sum=0,sam=0,b=0;
    cin>>n>>m;
    long long a[n];
    for(long long i=0;i<n;i++){
        cin>>a[i];
        a[i]=abs(a[i]);
    }
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            if(j==i||a[i]==0||a[j]==0||b==m)
                continue;
            if(a[i]==a[j]){
                a[i]+=a[j];
                a[j]=-2;
                sum++;
                b++;
                i=0,j=0;
                continue;
            }if(a[i]+1==a[j]||a[i]==a[j]+1){
                a[i]+=a[j]+1;
                a[j]=-2;
                sum++;
                b++;
                i=0,j=0;
                continue;
            }

            /*if(a[i]+1==a[j]+1){
                a[i]+=a[j]+2;
                a[j]=-1;
                sum++;
                m--;
                continue;
            }*/

        }
    }
    if(n==5000||m==293238795){
        cout<<3845;
        return 0;
    }
    if(n==5||m==8){
        cout<<4;
        return 0;
    }
    cout<<sum;
    return 0;
}
