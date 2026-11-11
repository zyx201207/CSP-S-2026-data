#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n+5);
    vector<int>ap(m+5,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<bool>st(m+5,0);
        vector<int>sv(n+5);
        int h=0;
        for(int j=i;j<=n;j++){
            if(st[a[j]]==0){
                sv[++h]=a[j];
                st[a[j]]=1;
            }else{
                while(sv[h]!=a[j]){
                    st[sv[h]]=0;
                    h--;
                }
            }
        }
        for(int i=1;i<=h;i++){
            ap[sv[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ap[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
