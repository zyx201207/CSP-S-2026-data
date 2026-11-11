#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qu;
struct Node{
    int kk,a[501];
}l[500001];
struct station{
    int w,tl[21],lid;
}s[501];
queue<int>q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway,out","w",stdout);
    scanf("%d%d%d%d%d",c,n,m,d,qu);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",x);
        s[i].w=2*x;
        s[i].lid=0;
    }
    for(int i=0;i<m;i++){
        scanf("%d",l[i].kk);
        for(int j=0;j<l[i].kk;j++){
            scanf("%d",l[i].a[j]);
            s[l[i].a[j]].tl[s[i].lid]=i;
        }
    }
    bool flag=false;
    while(qu--){
        int x,y,cnt=0;
        scanf("%d%d",x,y);
        q.push(x);
        while(!q.empty()){
            if(flag){
                break;
            }
            for(int i=0;i<s[q.front()].lid;i++){
                for(int j=0;j<l[s[q.front()].tl[i]].kk;j++){
                    q.push(l[s[q.front()].tl[i]].a[j]);
                }
            }
            for(int i=0;i<q.size();i++){
                if(y=q.front()){
                    cnt--;
                    flag=true;
                    break;
                }
            }
            cnt++;
        }
    }
    return 0;
}
