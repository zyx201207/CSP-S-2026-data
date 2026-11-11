#include<bits/stdc++.h>
using namespace std;
long long a[1000004];long long n;
char ch[1000004];
long long cnt;
struct ann{
    long long l,r;
};
vector<long long> t;
long long uni[1000004];
long long pos;long long L=0;
long long get(long long l,long long r){
    long long x1=upper_bound(a+1,a+n+1,l)-a-1;
    char c1=ch[x1];
    long long nl=L-r,nr=L-l;
    long long x2=upper_bound(a+1,a+n+1,nl)-a-1;
    char c2=ch[x2];
//    cout<<x1<<' '<<x2<<endl;
    if(c1==c2){
        return 0;
    }
    return (r-l);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++){
        long long x;
        char c;
        cin>>x>>c;
        a[i]=L;
        ch[i]=c;
        L+=x;
        t.push_back(L);
        uni[++pos]=L;
    }
//    for(int i=1;i<=n;i++){
//        cout<<a[i]<<' ';
//    }
//    cout<<endl;
    for(auto i:t){
        uni[++pos]=L-i;
    }
    sort(uni+1,uni+pos+1);
    long long _1=unique(uni+1,uni+pos+1)-uni-1;
    pos=_1;
//    for(int i=1;i<=pos;i++){
//        cout<<uni[i]<<' ';
//    }
//    cout<<endl;
    for(int i=1;i<=pos;i++){
        cnt+=get(uni[i-1],uni[i]);
    }
    cout<<cnt/2;
}
