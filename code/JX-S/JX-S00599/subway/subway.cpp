#include<bits/stdc++.h>
using namespace std;
long long subline[505][500005];
int sum[100000];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m],b,e;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int s=0;
        cin>>s;
        for(int j=1;j<=s;j++){
            int a,b;
            cin>>a>>b;
            subline[i][a]=b;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>b>>e;
        if(b>e){
            int t=e;
            e=b;
            b=t;
        }
        sum[i]=sum[i]+w[b]+w[e];
        for(int j=1;j<=n;j++){
            if(subline[j][b]!=0 and subline[j][b+1]!=0){
                sum[i]+=subline[j][b];
                while(subline[j][b]!=0 and b<=e){
                    b++;
                }
                sum[i]+=subline[j][b-1];
            }
        }

    }
    for(int i=1;i<=q;i++){
        cout<<sum[i]<<endl;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
