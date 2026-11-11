#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
unordered_set<int> st;
signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    freopen("card.in","r",stdin);freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool A,B;
    int __cntB=0;
    A=B=1;
    vector<int> cnt(m+1,0);
    vector<int> a(n+5);
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) A=0;
        if(i>0&&a[i]!=a[i-1]) __cntB++;
        if(__cntB>4999) B=0;
    }
    if(A){

        //return 0;
    }
    for(int i=1;i<=n;i++){
        //cout<<"Game "<<i<<endl;
        mp.clear();st.clear();
        for(int j=i;j<=n;j++){
            //cout<<"round "<<j<<endl;
            //cout<<"insert "<<a[j]<<endl;
            if(mp.count(a[j])==0){
                st.insert(a[j]);
                mp[a[j]]=j;
            }else{
                for(int k=mp[a[j]]+1;k<j;k++){
                    st.erase(a[k]);
                    mp.erase(a[k]);
                    //cout<<"erase "<<a[k]<<' ';
                }
                //cout<<endl;
                mp[a[j]]=j;
            }
        }
        //cout<<"=========\n";
        for(auto i:st){
            //cout<<i<<' ';
            cnt[i]++;
        }//cout<<"---------\n";
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }cout<<endl;
    return 0;
}
