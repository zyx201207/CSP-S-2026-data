#include<iostream>
#include<cstring>

using namespace std;

int n,m,lst;
int card[300070];
int place[500070];
int cnt[300070];
int cur[500070];
bool y[300070];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
        cin>>card[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if(place[card[j]]!=0&&place[card[j]]<=lst)lst=place[card[j]]-1;
            lst++;
            place[card[j]]=lst;
            cur[lst]=card[j];
        }
        for (int j = 1; j <= lst; j++)
            y[cur[j]]=1;
        for (int j = 1; j <= lst; j++)
            cnt[cur[j]]+=y[cur[j]];
        
        memset(place,0,sizeof(place));
        memset(cur,0,sizeof(cur));
        lst=0;
    }
    
    for (int i = 1; i <= m; i++)cout<<cnt[i]<<' ';
    

    return 0;
}