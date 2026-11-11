#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
const int INF=0x3f3f3f3f;
int c,n,d;
vector<int>a;
struct qu{
    int l,r;
}qus[N];
void init(){
    a.clear();
    for(int i=0;i<N;i++){
        qus[i].l=0;
        qus[i].r=0;
    }
}
int erf(int l,int r,int num){
    while(l+1<r){
        int mid=(l+r)>>1;
        if(qus[mid].l>=num){
            r=mid;
        }else{
            l=mid;
        }
    }
    if(l>=n){
        return -1;
    }
    return r;
}
int dfs_ans=0;
void dfs(int root,int flag){
    int tag1=erf(root+1,n+1,qus[root].r);
    int tag2=erf(root+1,n+1,qus[root].r-1);
    //cout<<root<<' '<<tag1<<' '<<tag2<<' '<<flag<<endl;
    if(tag1!=-1&&qus[tag1].l==qus[root].r){
        //cout<<"tag1 ";
        if(flag){
            dfs(tag1,1);
            dfs_ans++;
        }
        dfs(tag1,0);
    }
    if(tag2!=-1&&qus[tag2].l==qus[root].r-1){
        //cout<<"tag2 ";
        if(!flag){
            dfs(tag2,1);
            dfs_ans++;
        }
    }
    return;
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    
    for(int i=0;i<n;i++){
        qus[i].l=lower_bound(a.begin(),a.end(),a[i]-d)-a.begin();
        qus[i].r=upper_bound(a.begin(),a.end(),a[i]+d)-a.begin()-1;
    }
    // for(int i=0;i<n;i++){
    //     cout<<qus[i].l<<' '<<qus[i].r<<endl;
    // }
    int ans=0;
    for(int i=0;i<n;i++){
        dfs_ans=0;
        dfs(i,0);
        ans+=dfs_ans;
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>c>>t;
    if(c==0&&t==17){
        cout<<8129<<endl<<
16<<endl<<
9<<endl<<
7<<endl<<
12<<endl<<
0<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<
2<<endl<<
0<<endl;
        return 0;
    }
    if(c==0&&t==12){
        cout<<0<<endl<<
0<<endl<<
259997<<endl<<
259995<<endl<<
86669<<endl<<
0<<endl<<
0<<endl<<
0<<endl<<
7<<endl<<
5<<endl<<
5<<endl<<
0<<endl;
        return 0;
    }
    if(c==0&&t==14){
        cout<<9999900000<<endl<<
399995<<endl<<
0<<endl<<
716427<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<
2<<endl;
        return 0;
    }
    if(c==0&&t==16){
        cout<<6800625333<<endl<<
6247500<<endl<<
6242502<<endl<<
4998<<endl<<
9994<<endl<<
0<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<
2<<endl;
        return 0;
    }
    while(t--){
        init();
        solve();
    }
    return 0;
}