#include <bits/stdc++.h>
using namespace std;
struct node{
    int a;
    short b;
};
int n,now,mid,j=0;
long long s=0,ans,ss=0;
node a[200005];
char b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>now>>b;
        s+=now;
        a[i].a = now;
        a[i].b = b-'a';
    }
    s = s/2;
    for(int i=0;i<n;i++){
        ss+=a[i].a;
        if(ss>s){
            mid = i;
            break;
        }
    }
    while(j<=mid&&j<=now){
        if(a[j].b==a[now].b){
            if(a[j].a>a[now].a){
                a[j--].a-=a[now--].a;
            }else if(a[j].a==a[now].a){
                now--;
            }else{
                a[now].a-=a[j].a;
            }
        }else{
            if(a[j].a>a[now].a){
                now--;
                a[j].a-=a[now].a;
                ans+=a[now].a;
                j--;
            }else if(a[j].a==a[now].a){
                ans+=a[now--].a;
            }else{
                ans+=a[j].a;
                a[now].a-=a[j].a;
            }
        }
        j++;
    }
    cout<<ans;
    return 0;
}
