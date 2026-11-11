#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
ull tot;
struct str{
    ull t;
    char c;

    bool operator==(str a) const{
        return a.t==t&&a.c==c;
    }
};

deque<str> a; //use for() to add the string must dao/zhi TLE


void rebuild(){  //rebuild the vec zhe/shu/ru/fa/ye/tai/lan/le/ba
    auto i=a.begin()+1;
    for(;i!=a.end();i++){
        auto x=i-1;
        if( (*x).c == (*i).c ){
            if(x==a.begin())(*i).t+= (*x).t,a.pop_front(); 
            else (*i).t+= (*x).t,i=a.erase(x);
        }
    }
}

void print(){
    for(auto i:a){
        for(int j=0;j<i.t;j++) cout<<i.c;
        cout<<" ";
    }
}


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        ull t;
        char c;
        cin>>t>>c;
        a.push_back({t,c});
    }
    rebuild();
    //print();
    if(a.size()==1){ cout<<0<<endl; return 0;}

    //zhe/shi/sha/shi/shan
    //shen/mi/die/dai/qi/(iterator)
    //我感觉肯定有佬能10行代码切了
    //这迭代器快堆成答辩了
    //按理来说这应该是个普及-
    //不能这么复杂阿
    //咋还有人玩扫雷哈哈哈
    //vector erase的速度。。 不能超时吧
    //deque直接pop行不行
    //答案不一样了 vec是对的 emm
    //知道问题在那了 erase不是每次删第一个
    //加条if吧
    //想用list 这样rebuild就是O（n） 但是list无法完成下面的操作。。
    auto s=a.begin(),e=a.end(); e--;
    for(;s<e;){
        if(*s==*e) s++,e--;
        else{
            if((*s).t==(*e).t) tot+=(*s).t,s++,e--;  //c is not same
            else{
                if(!((*s).c==(*e).c)) tot+=min((*s).t,(*e).t);

                if((*s).t>(*e).t) 
                    (*s).t-=(*e).t,e--;  //forward the finished str
                else (*e).t-=(*s).t,s++; //delete the cmp-finished str
            }
         }
    }

    cout<<tot<<endl;

    return 0;
}
