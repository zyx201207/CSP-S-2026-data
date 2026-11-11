#include<bits/stdc++.h>
using namespace std;
struct ST{
    long long head,next,num;
    char c;
};
const long long N=2e5+10;
ST a[N<<1];long long tot,cnt;
long long n,ans ;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    for(long long i=1;i<=n;i++){
        long long num;
        char x;
        cin>>num>>x;
        a[i].head=i-1;
        a[i].next=i+1;
        a[i].num=num;
        a[i].c=x;
        tot+=num;
    }cnt=n+1;
    long long l=1,r=n;
    long long ttot=0;

    while(l!=r){
        if(a[l].num<a[r].num){
            a[a[r].head].next=++cnt;
            a[cnt].head=a[r].head;
            a[cnt].next=r;
            a[cnt].num=a[r].num-a[l].num;
            a[cnt].c=a[r].c;
            a[r].head=cnt;
            a[r].num=a[l].num;
        }else if(a[l].num>a[r].num){
                 a[a[l].next].head=++cnt;
                 a[cnt].head=l;
                 a[cnt].next=a[l].next;
                 a[cnt].num=a[l].num-a[r].num;
                 a[cnt].c=a[l].c;
                 a[l].next=cnt;
                 a[l].num=a[r].num;
        }
        //cout<<l<<".."<<r<<endl;
        if(a[l].next==r) break;
        l=a[l].next;
        r=a[r].head;

    }
/*
    for(long long i=1;i!=n+1;i=a[i].next){
        cout<<a[i].num<<":"<<a[i].c<<endl;
    }
*/
    l=1,r=n;
    while(l!=r){
        if(a[l].c!=a[r].c){
            ans+=a[l].num;
        }
        //cout<<l<<".."<<r<<endl;
        if(a[l].next==r) break;
        l=a[l].next;
        r=a[r].head;

    }
    cout<<ans;
    return 0;
}

