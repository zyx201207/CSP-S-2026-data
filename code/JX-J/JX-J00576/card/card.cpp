#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    int used[m]={};
    int cnt[m]={};
    int w=0;
    while(m--){
        for(int i=w;i<n;i++){
            used[a[i]]++;
            if(used[a[i]]>1){
                while(i--){
                    used[a[i]]=0;
                }
                used[a[i]]=1;
            }
        }
        for(int i=w;i<n;i++){
            if(used[a[i]]==1) cnt[a[i]]++;
        }
        w++;
    }
    for(int i=0;i<n;i++){
        cout<<cnt[a[i]]<<' ';
    }
    return 0;
}
