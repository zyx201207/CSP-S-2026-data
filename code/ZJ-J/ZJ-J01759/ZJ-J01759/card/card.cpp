#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long m,n,a[100000];
    cin>>n>>m;
    int solve[m];
    for(int i=0;i<m;i++){
        solve[i]=0;
    }
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    long long b[100000];
    long long cnt;
    for(long long i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<100000;j++){
            b[j]=0;
        }
        //game
        for(long long j=i-1;j<n;j++){
            //search
            for(long long z=0;z<cnt;z++){
                if(b[z] == b[j]){
                    long long cnt2=0;
                    b[j]=0;
                    for(long long y=z;y<cnt;y++){
                        b[y]=0;
                        cnt2++;
                    }
                    cnt-=cnt2;
                    break;
                }

            }
            b[cnt]=a[j];
            cnt++;
        }
        //game finish
        int flag2[m];
        for(int j=0;j<m;j++){
            flag2[j]=1;
        }
        for(int j=0;j<cnt;j++){
            if(flag2[b[j]-1]){
                flag2[b[j]-1]=0;
                solve[b[j]-1]++;
            }
        }
    }
    for(long long i=0;i<m;i++){
        cout<<solve[i]<<" ";
    }
    return 0;
}
