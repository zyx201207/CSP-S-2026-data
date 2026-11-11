#include <bits/stdc++.h>
using namespace std;
long long cnt,n,sum;
struct str{
    long long sl;
    char ch;
};
deque<str> a;
inline void cmp(){
    if(a.front().ch==a.back().ch){
        if(a.front().sl>a.back().sl){
            a.front().sl-=a.back().sl;
            a.pop_back();
        }else if(a.front().sl<a.back().sl){
            a.back().sl-=a.front().sl;
            a.pop_front();
        }else{
            a.pop_back();
            if(a.empty()){
                return;
            }
            a.pop_front();
        }
    }else{
        if(a.front().sl>a.back().sl){
            cnt+=a.back().sl;
            a.front().sl-=a.back().sl;
            a.pop_back();
        }else if(a.front().sl<a.back().sl){
            cnt+=a.front().sl;
            a.back().sl-=a.front().sl;
            a.pop_front();
        }else{
            cnt+=a.front().sl;
            a.pop_back();
            if(a.empty()){
                return;
            }
            a.pop_front();
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        struct str v;
        cin>>v.sl>>v.ch;
        sum+=v.sl;
        a.push_back(v);
    }
    while(!a.empty()){
        cmp();
    }
    cout<<cnt;
    return 0;
}