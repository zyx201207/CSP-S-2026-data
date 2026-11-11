#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int sum;
    char c;
};
int n;
node a[200005];
ll allsize;
stack<pair<int,char> >s;
queue<pair<int,char> >q;
ll ans;
void push_in(){
    if(allsize%2){
        ll mid=allsize/2+1;
        ll ws=0;
        bool flag=1;
        for(int i=1;i<=n;i++){
            ws+=a[i].sum;
            if(mid>=ws){
                s.push(make_pair(a[i].sum,a[i].c));
            }else{
                if(flag){
                    if(mid-(ws-a[i].sum)-1!=0){
                       s.push(make_pair(mid-(ws-a[i].sum)-1,a[i].c));
                    }
                    q.push(make_pair(ws-mid,a[i].c));
                    flag=0;
                }else{
                    q.push(make_pair(a[i].sum,a[i].c));
                }
            }
        }
    }else{
        ll mid=allsize/2;
        ll ws=0;
        bool flag=1;
        for(int i=1;i<=n;i++){
            ws+=a[i].sum;
            if(mid>=ws){
                s.push(make_pair(a[i].sum,a[i].c));
            }else{
                if(flag){
                    s.push(make_pair(mid-(ws-a[i].sum),a[i].c));
                    q.push(make_pair(ws-mid,a[i].c));
                    flag=0;
                }else{
                    q.push(make_pair(a[i].sum,a[i].c));
                }
            }
        }
    }
    return;
}
void solve(){
    while(s.empty()==0&&q.empty()==0){
       int sum1,sum2;
        char c1,c2;
        pair<int,char> fr=s.top();
        pair<int,char> ba=q.front();
        sum1=fr.first;
        sum2=ba.first;
        c1=fr.second;
        c2=ba.second;
        if(sum1>=sum2){
            sum1-=sum2;
            ans+=(((int)(c1!=c2))*sum2);
            //cout<<"pop"<<c2<<"\n";
            q.pop();
            s.top().first=sum1;
        }else{
            sum2-=sum1;
            ans+=(((int)(c1!=c2))*sum1);
            //cout<<"pop"<<c1<<"\n";
            s.pop();
            q.front().first=sum2;
        }
    }

    return;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].sum>>a[i].c;
        allsize+=a[i].sum;
    }
    push_in();
    solve();
    cout<<ans;
    return 0;
}
// orz rp++ csp-j1= made by cici
//all right 100pts
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
