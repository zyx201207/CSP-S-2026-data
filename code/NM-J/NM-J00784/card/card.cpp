#include<bits/stdc++.h>
using namespace std;
int search(vector<int> x,int target){
    int len=x.size();
    for(int i=0;i<len;i++)
        if(x[i]==target)return i;
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    vector<int> card,desk,cnt;
    cin >> n >> m;
    cnt.resize(m);
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        card.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int result=search(desk,card[j]);
            if(result)desk.resize(result);
            desk.push_back(card[j]);
        }
        for(int j=0;j<desk.size();j++){
            cnt[desk[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << cnt[i] << ' ';
    }
    return 0;
}