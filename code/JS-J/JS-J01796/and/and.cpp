#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool cmp(long long aa,long long bb){
    long long x=aa,y=bb;
    string x2="";
    string y2="";
    stack<long long> s;
    while(x){
        long long c=x%2;
        s.push(c);
        x/=2;
    }
    while(!s.empty()){
        long long c=s.top();
        string cc=to_string(c);
        x2+=cc;
        s.pop();
    }
    while(y){
        long long c=y%2;
        s.push(c);
        y/=2;
    }
    while(!s.empty()){
        long long c=s.top();
        string cc=to_string(c);
        y2+=cc;
        s.pop();
    }
    return x2<y2;
}
int main(){

    freopen("and,in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    long long maxn=INT_MIN;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);


maxn=a[n]&a[n-1];
for(int i=2;i<m;i++){
    maxn=maxn&a[n-i];
}
    cout<<maxn;

    return 0;
}
