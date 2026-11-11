#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*1e5+10;
struct Point{
    char c;
    long long num;
}p[MAXN];
void st(int &i,int &j,int n,long long &ans){
    for(;;){
        if(p[i].num<=0) i++;
        if(p[j].num<=0) j--;
        if(i>j) return;
        if(p[i].num>0&&p[j].num>=0){
            int x=min(p[i].num,p[j].num);
        if(p[i].c!=p[j].c) ans+=x;
        p[i].num-=x,p[j].num-=x;
    }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
            long long v;
    char c;
        cin>>v>>c;
        p[i].c=c;
        p[i].num=v;

    }
int i=0;int j=n-1;
    st(i,j,n,ans);
 cout<<ans;
    return 0;
}
