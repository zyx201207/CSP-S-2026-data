#include<bits/stdc++.h>
using namespace std;
struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
    bool operator<(const Point& other)const{
        if(x!=other.x) return x<other.x;
        else return y<other.y;
    }
    friend std::ostream operator<<(const ostream& os,Point& p){
//        os<<p.x;
//        return os;
    }
};
struct node{
    int x,y,time;
};
queue<node>q;
void bfs();
class Solution{
public:
    static bool cmp(const Point&a,const Point&b){
        if(a.x!=b.x)return a.x<b.x;
        else return a.y<b.y;
    }
    void sortPoints(Point&points){
       // std::sort(begin,after,cmp);
    }
};
void dfs(){}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
//    for(auto t:points){
        //cout<<p;
    //}
    cout<<LONG_MAX<<endl;
    cout<<(long long )1e18+10;
    ;
}
