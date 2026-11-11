#include<iostream>
#include<cstdio>
#include<queue>
#include<deque>
using namespace std;
int n,m,arr[200005],ans[100005];
bool o[100005];
deque<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=n;i++){
        for(int i=1;i<=m;i++){
            o[i]=false;
        }
        for(int j=i;j<=n;j++){
            int h=arr[j];
            if(!o[h]){
                o[h]=true;
                q.push_back(h);
            }else{
                while(!q.empty()&&q.back()!=h){
                    o[q.back()]=false;
                    q.pop_back();
                }
            }
        }
        while(!q.empty()){
            ans[q.back()]++;
            q.pop_back();
        }
    }

    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
