#include<bits/stdc++.h>
using namespace std;
#define pic pair<int,char>
#define num first
#define ch second
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    long long ans=0LL;
    vector<pic> a(n);
    for(int i=0;i<n;i++) cin>>a[i].num>>a[i].ch;
    vector<pic> b=a;
    reverse(b.begin(),b.end());
    while(a.size()+b.size()>n/2){
        int t1=a[0].num,t2=b[0].num,dif=abs(t1-t2);
        char c1=a[0].ch,c2=b[0].ch;
        bool k=(c1!=c2);
        ans+=(long long)min(t1,t2)*(long long)k;
        a.erase(a.begin()),b.erase(b.begin());
        if(t1>t2) a.insert(a.begin(),make_pair(dif,c1));
        else if(t1<t2) b.insert(b.begin(),make_pair(dif,c2));
    }
    cout<<ans;
    return 0;
}
