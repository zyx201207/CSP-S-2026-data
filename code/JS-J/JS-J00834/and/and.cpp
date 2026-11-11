#include<bits/stdc++.h>
using namespace std;
bool b[200005][31];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    set<int> s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(i);
        int j=30;
        int tmp=a[i];
        while(j>=0 && tmp>0){
            b[i][j]=(tmp>=pow(2,j));
            if(b[i][j]) tmp-=pow(2,j);
            j--;
        }
    }

    int ans=0;
    for(int j=30;j>=0;j--){
        int cnt=0;
        for(auto it=s.begin();it!=s.end();it++) if(b[*it][j]==1) cnt++;
        if(cnt>=m){
            ans+=pow(2,j);
            set<int> tmp;
            for(auto it=s.begin();it!=s.end();it++) if(b[*it][j]==1) tmp.insert(*it);
            s.clear();
            for(auto it=tmp.begin();it!=tmp.end();it++) s.insert(*it);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
