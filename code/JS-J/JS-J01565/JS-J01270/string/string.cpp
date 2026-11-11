#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,char> > a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,siz=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long num;
        char c;
        cin>>num>>c;
        siz+=num;
        a.push_back(make_pair(num,c));
    }
    long long ans=0;
    long long dl=0,dr=n-1;
    while(dl<dr){
        long long n1,n2;
        char c1,c2;
        n1=a[dl].first;
        n2=a[dr].first;
        c1=a[dl].second;
        c2=a[dr].second;
        if(c1!=c2){
            ans+=min(n1,n2);
        }
        if(n1<n2){
            dl++;
            a[dr].first-=n1;
        }
        else if(n1>n2){
            dr--;
            a[dl].first-=n2;
        }
        else{
            dl++;
            dr--;
        }
    }
    cout<<ans;
    return 0;
}
