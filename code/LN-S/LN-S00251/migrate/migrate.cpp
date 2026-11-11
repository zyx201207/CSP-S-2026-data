#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,biao[2000050],shu[2000050];
long long aaa(long long biao[2000050],long long n,long long shu[2000050],long long b){
    for(long long i=0+b;i<n;i++){
        for(long long j=i+1;j<n;j++){
            if(biao[j]-biao[i]<=d){
                shu[j]++;
            }else{
                break;
            }
        }
    }
    for(long long i=0+b;i<n;i++){
        for(long long j=i+1;j<n;j++){
            if((biao[j]-biao[0+b])%d==0 || (biao[j]-biao[0+b])<=d){
                shu[j]=1;
            }
        }
    }
    return shu[2000050];
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(long long i=0;i<n;i++){
            cin>>biao[i];
            shu[i]=0;
        }
        long long zong=0;
        for(long long j=0;j<n-1;j++){
            for(long long k=0;k<n;k++){
                shu[k]=0;
            }
            aaa(biao,n,shu,j);
            long long he=0;
            for(long long i=0;i<n;i++){
                if(shu[i]==2){
                    he++;
                }
            }
            zong+=he;
        }
        cout<<zong<<endl;
    }
    return 0;
}
