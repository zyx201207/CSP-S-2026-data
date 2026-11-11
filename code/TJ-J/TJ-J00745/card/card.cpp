#include<iostream>
using namespace std;
int a[300005],n,m,card[500005];
string ontable="";
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(ontable.find(char(card[j]+'0'))!=ontable.npos){
                int x=ontable.find(char(card[j]+'0'));
                ontable.erase(x,ontable.size()-x);
            }
            ontable+=char(card[j]+'0');

        }
        for(int j=0;j<ontable.size();j++){
            a[ontable[j]-'0']++;
        }
        ontable="";
    }
    for(int i=1;i<=m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
