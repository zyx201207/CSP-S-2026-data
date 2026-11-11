#include <bits/stdc++.h>
using namespace std;
int ans[300006];
int tmp[300006];
int main(){
#ifndef debug
freopen("card.out","w",stdout);
freopen("card.in","r",stdin);
#endif
    int n,m;
    cin>>n>>m;
    vector<int> cards;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        cards.push_back(t);
    }
    for(int i=0;i<n;i++){
        vector <int> resault;
        for(int j=i;j<n;j++){
            if(tmp[cards[j]]){
                    int t=tmp[cards[j]]-1;
                    while(resault.size()>t){tmp[resault[t]]=0;
                resault.erase(resault.begin()+t);
                }

            }
            resault.push_back(cards[j]);
            tmp[cards[j]]=resault.size();
        }
        for(auto i:resault){
            ans[i]++;tmp[i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
#ifndef debug
fclose(stdout);
fclose(stdin);
#endif
    return 0;
    }
