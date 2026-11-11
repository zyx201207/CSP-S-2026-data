#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=3e3+10;
int n,m;
int a[N];
int cnt[N];
int pos[M];//pos[i]:元素i出现的位置
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int t=1;t<=n;t++){
        int f=0;//牌堆的大小，初始是0
        for(int i=0;i<=m;i++){
            pos[i]=-1;
        }
        vector<int> q;
        q.push_back(0);//转成1下标
        for(int i=t;i<=n;i++){
            if(pos[a[i]]!=-1){//如果这张牌先前用过（有位置
                for(int j=pos[a[i]];j<=f;j++){//
                    pos[q.back()]=-1;
                    q.pop_back();
                }
                f=pos[a[i]];//牌堆的大小回到清除后的大小
            }
            pos[a[i]]=++f;
            q.push_back(a[i]);
        }
        for(int i=1;i<=m;i++){
            if(pos[i]!=-1){
                cnt[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}