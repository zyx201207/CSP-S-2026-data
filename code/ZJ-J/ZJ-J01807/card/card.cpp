#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int tcard[50000];
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m,a[50000];
    
    //memset(tcard,0,sizeof(tcard));
    scanf("%d %d",&n,&m);
    for(int i = 1; i  <=n ; i++){
        scanf("%d",&a[i]);
    }

    for(int I = 1 ; I <= n ; I++){
        
        int card[30000];
        vector<int> cardp;
        memset(card,-1,m);
        for(int i = I ; i <= n ; i++){
            cardp.push_back(a[i]);
            if(card[a[i]]==-1)
                card[a[i]] = i;
            else{
                for(int o = i ; o > card[a[i]] ; o--)
                    cardp.pop_back();
                cardp[a[i]] = i;
            }
        }


        for(int i = 0 ; i < cardp.size() ; i++){
            tcard[cardp[i]]++;
        }
    }
    for(int i = 1 ; i <= m ; i++){
        printf("%d ",tcard[i]);
    }
    return 0;    
}
