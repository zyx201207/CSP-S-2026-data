#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
void init(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
}
struct node{
    char s;
    int n;
};
int n;
int s_size,now_size;
node stri;
vector<node> str;
int cnt;
queue<node> q1,q2;
signed main(){
    init();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stri.n>>stri.s;
        if(str.size()){
            if(stri.s!=str[str.size()-1].s){
                str.push_back(stri);
            }
            else {
                str[str.size()-1].n+=stri.n;
            }
        }else{
            str.push_back(stri);
        }
        s_size+=stri.n;
    }
    now_size=s_size/2;
    for(auto x:str){
        if(now_size>=x.n){
            q1.push(x);
            now_size-=x.n;
            if(now_size==0) break;
        }else{
            q1.push({x.s,now_size});
            break;
        }
    }
    now_size=s_size/2;
    for(int i=str.size()-1;;i--){
        if(now_size>=str[i].n){
            q2.push(str[i]);
            now_size-=str[i].n;
            if(now_size==0) break;
        }else{
            q2.push({str[i].s,now_size});
            break;
        }
    }
    while(true){
        auto t1=q1.front(),t2=q2.front();
        if(t1.s!=t2.s){
            cnt+=min(t1.n,t2.n);
        }
        if(t1.n>t2.n){
            q2.pop();
            q1.front().n-=t2.n;
        }else if(t1.n<t2.n){
            q1.pop();
            q2.front().n-=t1.n;
        }else{
            q1.pop();
            q2.pop();
        }
        if(!(q1.size() and q2.size())){
            break;
        }
    }
    cout<<cnt;
    return 0;
}
