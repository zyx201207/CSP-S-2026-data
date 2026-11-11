#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    bool f=true;
    for(int i=2;i<=n;i++){
        if(a[i-1]>=a[i]) f=0;
    }
    if(f){
        vector<int> cnt(m+1);
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
        }
        int k=m;
        for(int i=1;i<=m;i++){
            if(cnt[i]!=0){
                cout<<k<<" ";
                k=1;
            }else{
                cout<<0<<" ";
            }
        }
    }else{
        vector<int> cnt(m+1);
        vector<int> cur;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if((int)cur.size()==0){
                    cur.push_back(a[j]);
                }
                else{
                    auto it=find(cur.begin(),cur.end(),a[j]);
                    if(it!=cur.end()){
                        while(cur.back()!=a[j]) cur.pop_back();
                    }else{
                        cur.push_back(a[j]);
                    }
                }

            }
            for(auto &x:cur) cnt[x]++;
        }
        for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    }
    return 0;
}
