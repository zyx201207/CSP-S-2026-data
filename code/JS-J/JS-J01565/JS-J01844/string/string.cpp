#include <bits/stdc++.h>
using namespace std;
struct node{
    long a;
    char c;
}rm[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n;
    cin>>n;
    long long sum=0;
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>rm[i].a>>rm[i].c;
        sum+=rm[i].a;

    }
    int j=0;
    int p1=1,p2=n;
    while(1){
        if(rm[p1].a==-1||rm[p2].a==-1) break;
        int cha=abs(rm[p1].a-rm[p2].a);
        int minn=min(rm[p1].a,rm[p2].a);
        if(rm[p1].a>rm[p2].a){
            rm[p1].a=cha;
            if(rm[p1].c!=rm[p2].c){
                ans+=minn;

            } rm[p2].a=-1;
            p2--;
        }
        else if(rm[p1].a<rm[p2].a){
            rm[p2].a=cha;
            if(rm[p1].c!=rm[p2].c){
                ans+=minn;

            }rm[p1].a=-1;
            p1++;
        }
        else{
            if(rm[p1].c!=rm[p2].c){
                ans+=minn;

            }rm[p1].a=-1;
                rm[p2].a=-1;
            p1++;
            p2--;
        }
    }
    cout<<ans;
    return 0;
}
