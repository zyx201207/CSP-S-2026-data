#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0,ans;
string s;
struct syh{
    int a;
    char c;
}p[2000001];
void aaa(int l,int r){
     while(l<r){
        if(p[l].a>=p[r].a){
            if(p[l].c==p[r].c){
                p[l].a-=p[r].a;
                p[r].a=0;
            }
            r--;
        }
        else if(p[l].a<p[r].a){
            if(p[l].c==p[r].c){
                p[r].a-=p[l].a;
                p[l].a=0;
            }
            l++;
        }
        else l++,r--;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].a>>p[i].c;
        if(p[i].c==p[i-1].c){
            p[i-1].a+=p[i].a;
            p[i].a=0;
        }
    }
    aaa(1,n);
    for(int i=1;i<=n;i++){
        if(p[i].a==0) continue;
        long long x=0,y=0;
        for(int u=1;u<i;u++) x+=p[u].a;
        for(int v=i+1;v<=n;v++) y+=p[v].a;
        if(x==y) {p[i].a=0;break;}
        else if(p[i].a>abs(x-y)){
            p[i].a-=abs(x-y);
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(p[i].a==0) continue;
        cnt+=p[i].a;
    }
    if(cnt<=1 && cnt!=-1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans+=p[i].a;
    }
    ans/=2;
    cout<<ans;
    return 0;
}
