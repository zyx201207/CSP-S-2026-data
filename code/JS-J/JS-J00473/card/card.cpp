#include<bits/stdc++.h>
using namespace std;
struct pp
{
    int p;
    int q;
};
vector<pp> mm(300000+1);
vector<int> mmm(300000+1);vector<int> nn(500000+1);vector<int> mn(500000+1);
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,pl;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>nn[i];
    }
    int pq;
    for (int i = 1; i <= n; i++)
    {
        pq=1;
        for (int j = i; j <= n; j++)
        {
            if (mm[nn[j]].p!=i)
            {
                mn[pq]=nn[j];
                mm[nn[j]].p=i;
                mm[nn[j]].q=pq;
            }
            else{
                pl=mm[nn[j]].q;
                for (int jpp = pl; jpp <= pq; jpp++)
                {
                    mm[mn[jpp]].p=0;
                    mn[jpp]=0;
                    mm[mn[jpp]].q=0;
                }
                mn[pl]=nn[j];
                mm[nn[j]].p=i;
                mm[nn[j]].q=pl;
                pq=pl;
            }
            pq+=1;
        }
        for(int lp=1;lp<=pq;lp++){
            mn[lp]=0;
        }
        for (int j = 1; j <= m; j++)
        {
            if(mm[j].p==i){
                mmm[j]+=1;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout<<mmm[i]<<' ';
    }
    return 0;
}
