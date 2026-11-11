#include <bits/stdc++.h>
using namespace std;
int cnt[300001];
int havefuck(string gay,char cc){
    for(int i=0;i<gay.size();i++){
        if(gay[i]==cc){
            return i;
        }else{
            return -1;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    char card[n+1];
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    for(int i=1;i<=n;i++){
        string gay="";
        for(int j=i;j<=n;j++){
            int tmp=havefuck(gay,card[j]);
            if(tmp!=-1){
                string gay1="";
                for(int i=0;i<tmp;i++){
                        gay1+=gay[i];
                }
                gay=gay1+card[j];
            }else{
                gay+=card[j];
            }
        }
        for(int j=0;j<gay.size();j++){
            cnt[gay[j]-'0']++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
