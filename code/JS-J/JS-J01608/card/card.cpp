#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[500005],l[500005],ans[300005];
bool ta=true;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[a[i]]=i;
        ta=ta && a[i]>=a[i-1];
    }
    if(ta){
        for(int i=1;i<=m;i++)cout<<l[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++){
        int j=i;
        while(j<=n){
            j=l[a[j]];
            ans[a[j]]++;
            j++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
/*
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int n,m,a[500005],l[300005],val[500005],ans[300005];
struct node{
    int id,val,in;
    node(int a,int b,int d):id(a),val(b),in(d){}
    bool operator<(const node& other)const{
        if(id!=other.id)return id<other.id;
    }
    bool operator>(const node& other)const{
        if(id!=other.id)return id>other.id;
    }
};
priority_queue<node,vector<node>,greater<node> >q;
int main(){
    //freopen("card3.in","r",stdin);
    //freopen("card3.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[a[i]]=i;
    }
    for(int i=n;i>=1;i--){
        if(val[a[i]]){
            while(q.top().val!=a[i]){
                ans[q.top().val]+=q.top().in-i;
                val[q.top().val]=0;
                q.pop();
            }
        }
        else{
            if(i==l[a[i]])q.push(node(i,a[i],i));
            else{
                while(!q.empty() && q.top().id<l[a[i]] || q.top().in<l[a[i]]){
                    ans[q.top().val]+=q.top().in-i;
                    val[q.top().val]=0;
                    q.pop();
                }
                q.push(node(l[a[i]],a[i],i));
            }
            val[a[i]]=1;
        }
    }
    while(!q.empty()){
        ans[q.top().val]+=q.top().in;
        q.pop();
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
*/
