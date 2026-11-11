#include<bits/stdc++.h>
using namespace std;
struct abcd{
    char c;
    long long cnt;
}abc[200005];
long long cnt=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        long long id;
        char ch;
        cin>>id>>ch;
        if(abc[i-1].c==ch){
            abc[i-1].cnt+=id;
            i--;
            n--;
        }
        else{
            abc[i].cnt=id;
            abc[i].c=ch;
        }
    }
    long long mid=(1+n)/2;
    for(long long l=1;l<=mid;l++){
        long long r=n-l+1;
        long long cha=abc[l].cnt-abc[r].cnt;
        bool same=abc[l].c==abc[r].c;
        if(same){
            if(cha){
                long long maxn=max(abc[l].cnt,abc[r].cnt);
                cnt+=maxn;
                if(maxn==abc[l].cnt) abc[l+1].cnt+=maxn-abc[r].cnt;
                else abc[r-1].cnt+=maxn-abc[l].cnt;
            }
        }
        else{
            if(r-l<=1){
                cnt+=min(abc[l].cnt,abc[r].cnt);
            }
            else if(cha){
                long long maxn=max(abc[l].cnt,abc[r].cnt);
                cnt+=maxn;
                if(maxn==abc[l].cnt) abc[l+1].cnt+=maxn-abc[r].cnt;
                else abc[r-1].cnt+=maxn-abc[l].cnt;
            }
            else cnt+=abc[l].cnt;
        }
//      cout<<l<<" "<<r<<" "<<cnt<<"\n";
    }
    cout<<cnt;
    return 0;
}
//change string to be a round-string
//1.same
//1.1.cha inco ->max(l,r)
//eg.aaabba->aabbaa / aabba->abbba
//1.2.cha co->/
//2.!same
//2.1.l next to r -> min(l,r)
//2.2.cha inco ->max(l,r) ->change max(l,r)
//2.3.cha co -> change
