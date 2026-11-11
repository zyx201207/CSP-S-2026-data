#include<bits/stdc++.h>
using namespace std;
int main(){
 //   freopen("card.in","r",stdin);
 //   freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int card[100];
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        vector<int>board;
        for(int j=i;j<=n;j++){
            for(int k=0;k<board.size();k++){
                if(board[k]==card[i]){
                    for(int l=k;l<board.size();l++){
                        board[l]=-1;
                    }
                }

            }
            board.push_back(card[i]);
        }
        for(int j=1;j<board.size();j++){
            if(board[j]==i){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
