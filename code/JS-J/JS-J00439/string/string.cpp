#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
struct node{
    int num;
    char c;
};
int n,ans=0;
deque<node>q;
node a[MAXN];
bool f,flag;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    char c;
    for(int i=1;i<=n;i++){
        int x;char y;
        cin>>x>>y;
        if(x!=1)f=1;
        a[i].c=y;
        if(a[1].c!=y)flag=1;
        q.push_back({x,y});
    }
    if(!flag){
        cout<<0;
        return 0;
    }
    if(!f){
        for(int i=1;i<=n/2;i++){
            if(a[i].c!=a[n-i+1].c){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    /*
    while(!q.empty()||q.size()!=1){
        node a;
        a.num=q.front().num;
        a.c=q.front().c;
        q.pop_front();
        node b;
        b.num=q.back().num;
        b.c=q.back().c;
        q.pop_back();

        if(a.c!=b.c){
            ans+=min(a.num,b.num);
            if(a.num>b.num){
                int res=a.num-b.num;
                q.push_front({res,a.c});
            }
            else{
                int res=b.num-a.num;
                q.push_back({res,a.c});
            }
        }
        else{
            if(a.num==b.num){
                continue;
            }
            else{
                if(a.num>b.num){
                    int res=a.num-b.num;
                    q.push_front({res,a.c});
                }
                else{
                    int res=b.num-a.num;
                    q.push_back({res,a.c});
                }
            }
        }

    }
    cout<<ans;
    */
    return 0;
}
