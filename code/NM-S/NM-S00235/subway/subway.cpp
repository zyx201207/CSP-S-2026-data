#include<iostream>
using namespace std;
struct subway{
    int num;
    int stns[500005];
    int stncount=0;
    int wait[500005];
};
subway lines[505];
struct station{
    int num;
    int lns[25];
    int lnscount=0;
    int lnswalk[25];
    int walk;
};
station stn[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        stn[i].num=i;
        cin>>stn[i].walk;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,b;
            cin>>a>>b;
            lines[i].stns[j]=a;
            stn[a].lnscount++;
            lines[i].stncount++;
            stn[a].lns[stn[a].lnscount]=i;
            stn[a].lnswalk[stn[a].lnscount]=b;
            lines[i].wait[j]=b;
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        for(int i=1;i<=stn[a].lnscount;i++){
            for(int j=1;j<=lines[stn[a].lns[i]].stncount;j++){
                if(lines[stn[a].lns[i]].stns[j]==b){
                    cout<<stn[a].walk+stn[a].lnswalk[i]+stn[b].walk+lines[stn[a].lns[i]].wait[j];
                }
            }
        }
    }
}
