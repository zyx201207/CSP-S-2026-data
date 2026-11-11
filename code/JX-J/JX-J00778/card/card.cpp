#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n+1);
    long long i;
    for (i=1;i<=n;i++){
        cin>>a[i];
    }
    long long j;
    bool skip=false;
    map<long long,long long> nums;
    for (j=1;j<=n;j++){
        vector<long long> card;
        unordered_set<long long> has;
        for (i=1+j-1;i<=n;i++){
            if (i!=n && a[i]==a[n]){
                card.push_back(a[n]);
                break;
            }
            if (has.count(a[i])){
                for (long long q=card.size()-1;q>=0;q--){
                    if (card[q]==a[i]){
                        card.pop_back();
                        break;
                    }
                    card.pop_back();
                }
                has.erase(a[i]);
            }
            card.push_back(a[i]);
            has.insert(a[i]);
        }
        for (i=0;i<card.size();i++){
            nums[card[i]]++;
        }
    }
    for (i=1;i<=m;i++){
        cout << nums[i];
        if (i!=m){
            cout<< " ";
        }
    }
    return 0;
};
