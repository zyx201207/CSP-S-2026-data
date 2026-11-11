#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<int> have;
    vector<int> card;
    bool a[m];
    long long sum[m];
    for(int i=0;i<m;i++){
        sum[i]=0;
    }
    for(int i=0;i<m;i++){
        a[i]=false;
    }
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        have.push_back(t);
    }
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            if(!m[j]){
                card.push_back(have[j]);
                m[j]=true;
            }else{
                card.erase(card.find(have[j]),card.end);
                card.push_back(have[j]);
                }
        }
        for(int k=0;k<card.size();k++){
            sum[card[k]-1]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<sum[i];
    }
    return 0;
}
