#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,sj[500050],a;
long long ab[505][500050][3];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=0;i<m;i++){
        cin>>sj[i];
    }
    for(long long i=0;i<n;i++){
        cin>>a;
        for(long long j=0;j<a;j++){
            cin>>ab[i][j][0]>>ab[i][j][1];
        }
    }
    for(long long i=0;i<q;i++){
        long long a1,b1;
        cin>>a1>>b1;
        long long ji=0;
        ji+=(sj[a1]+sj[b1]);
        for(long long j=0;j<n;j++){
            for(long long k=0;k<500050;k++){
                if(ab[j][k][0]<=m){
                    if(ab[j][k][0]==a1){
                        long long l=k;
                        while(l){
                            if(ab[j][l][0]<=b1){
                                ji+=ab[j][l][1];
                            }else{
                                break;
                            }
                        }
                    }
                }else{
                    break;
                }
            }
        }
        cout<<ji<<endl;
    }
    return 0;
}
