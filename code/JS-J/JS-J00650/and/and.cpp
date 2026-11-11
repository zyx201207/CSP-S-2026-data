#include<bits/stdc++.h>
using namespace std;

inline long long readint(){
    long long a=0;
    int c;
    bool f=0;
    c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-')f=1;
        c=getchar_unlocked();
    }
    while(c<='9'&&c>='0'&&c!=EOF){
        a=a*10+c-48;
        c=getchar_unlocked();
    }
    return f?-a:a;
}

int dfs(int b,int s,int m,int n,vector<int>&a){
    if(n-s<m)return 0;
    if(m==0)return b;
    return max(dfs(b,s+1,m,n,a),dfs(b&a[s],s+1,m-1,n,a));
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>a(n+3);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<dfs(((long long)1<<31)-1,1,m,n,a);
    return 0;
}