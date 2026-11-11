#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N];
unordered_map<int,int>p;
ll t[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        p.clear();
        for(int j=i;j<=n;j++){
            b[j-i+1]=a[j];
            t[a[j]]++;
        }
        for(int j=1;j<=n-i+1;j++){
            if(p[b[j]]==0)p[b[j]]=j;
            else{
                for(int k=p[b[j]];k<j;k++){
                    p[b[k]]=0;
                    t[b[k]]--;
                    b[k]=0;
                }
                p[b[j]]=j;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
