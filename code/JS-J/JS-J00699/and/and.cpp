#include<bits/stdc++.h>
using namespace std;
long long yu(long long x,long long y){
    long long sum=0;
    string s1={},s2={};
    while(x!=0&&y!=0){
        s1+=char(x%2);
        s2+=char(y%2);
    }
    int l1=s1.size(),l2=s2.size();
    if(l1!=l2){
        if(l1>l2){
            for(int i=1;i<=l1-l2;i++) s2=" "+s2;
        }
        else for(int i=1;i<=l2-l1;i++) s1=" "+s1;
    }
    int cnt=0;
    for(int i=max(l1,l2)-1;i>=0;i--){
        if(s1[i]=='1'&&s2[i]=='1') sum+=2^cnt;
        cnt++;
    }
    return sum;
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long a[200005];
    bool f[200005]={0};
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    long long maxn=-1;
    if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout << maxn << endl;
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                maxn=max(maxn,yu(a[i],a[j]));
            }
        }
        if(m==2){
            cout << maxn << endl;
            return 0;
        }
        else {
            m=m-2;
            while(m--){
                int num=maxn;
                for(int i=1;i<=n;i++){
                        if(f[i]==0) maxn=max(maxn,yu(num,a[i]));
                }
            }
            cout << maxn << endl;
        }
    }
return 0;
}
