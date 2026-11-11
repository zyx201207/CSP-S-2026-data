#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005],t[500005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    multiset<int> st;
    for(int i=1;i<=n;i++){
        st.clear();
        for(int j=i;j<=n;j++){
            if(st.size()>=1){
                auto t=st.end(); t--; t--;
                if(*t==a[j]){
                    for(int k=j;k<=m;k++){
                        st.erase(k);
                    }
                }
            }
            st.insert(a[j]);
        }
        for(auto it=st.begin();it!=st.end();it++){
            if(it==st.begin() || *it-1!=*it){
                t[*it]++;
            }
        }
    }

    for(int i=1;i<=m;i++){
        cout<<t[i]<<' ';
    }
    return 0;
}
