#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>v(n+2),usecard(m+1,0);
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++){
        //printf("play game %d time\n",i);
        vector<int>cards;
        for(int j=i;j<=n;j++){
            bool flg=true;
            int paiout=v[j];
            //printf("gives pai:%d\n",paiout);
            //printf("cards size:%d\n",cards.size());
            for(int k=0;k<cards.size();k++){
                if(cards[k]==paiout){
                    //printf("eat:%d\n",k);
                    cards.erase(cards.begin()+k,cards.end());
                    flg=true;
                }
            }
            if(flg){
                cards.push_back(paiout);
            }
        }
        for(int k=0;k<cards.size();k++){
            usecard[cards[k]]++;
        }
    }
    for(int i=1;i<m+1;i++){
        cout<<usecard[i]<<" ";
    }
    return 0;
}
