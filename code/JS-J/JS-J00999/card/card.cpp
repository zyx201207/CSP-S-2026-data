#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int cnt[300010];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int t=1; t<=n; t++){
        vector<int> vec;
        map<int,int> mp;
        int pos=-1;
        for(int i=t; i<=n; i++){
            vec.push_back(a[i]);
            pos++;
            if(mp.count(a[i])&&mp.at(a[i])!=-1){
                for(int j=mp.at(a[i])+1; j<pos; j++){
                    mp.at(vec[j])=-1;
                }
                vec.erase(vec.begin()+mp.at(a[i])+1,pos+vec.begin()+1);
                pos=mp.at(a[i]);
            }
            else{
                mp[a[i]]=pos;
            }
        }
        for(int j=0; j<=pos; j++){
            cnt[vec[j]]++;
        }
    }
    for(int i=1; i<=m; i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
