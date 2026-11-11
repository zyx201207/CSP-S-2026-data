#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int now[M];
int cnt[M];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int len=0;
        unordered_map<int,int> mp;
        for(int j=i;j<=n;j++){
            if(mp[a[j]]==0 || mp[a[j]]>len){
                now[++len]=a[j];
                mp[a[j]]=len;
            }
            else{
                len=mp[a[j]];
            }
        }
        for(int j=1;j<=len;j++){
            cnt[now[j]]++;
            now[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",cnt[i]);
    }
    return 0;
}
