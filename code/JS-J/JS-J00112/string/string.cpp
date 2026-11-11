#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
    int a;
    char c;
}f[N];
int a[N];
node s1[N], s2[N];
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, sum=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>f[i].a>>f[i].c;
        a[i]=a[i-1]+f[i].a;
        sum+=f[i].a;
    }
    bool ok=0;;
    if(sum&1) ok=1;
    sum=(sum+1)/2;
    //cout<<sum<<' ';
    int id;
    for(int i=1; i<=n; i++){
        if(a[i]>=sum) {
            id=i;
            //cout<<id<<' ';
            break;
        }
    }
    int l=1, r=1, ans=0;
    for(int i=1; i<id; i++){
        s1[i].a=f[i].a;
        s1[i].c=f[i].c;
        //cout<<s1[i].a<<' '<<s1[i].c<<' ';
    }
    int iid=id;
    bool flag=0;
    if(ok&&sum-a[id-1]==1&&sum&1) flag=1;
    if(sum-a[id-1]!=0&&!flag) s1[id].a=sum-a[id-1], s1[id].c=f[id].c, id++;
    //cout<<id<<' ';
    int up;
    if(a[iid]-sum!=0){
        s2[1].a=a[iid]-sum;
        s2[1].c=f[iid].c;
        for(int i=2; i<=n-iid+1; i++){
            s2[i].a=f[i+iid-1].a;
            s2[i].c=f[i+iid-1].c;
            //cout<<i<<' '<<s2[i].a<<' '<<s2[i].c<<' ';
        }
        up=n-iid+1;
    }
    else{
        for(int i=1; i<=n-iid; i++){
            s2[i].a=f[i+iid].a;
            s2[i].c=f[i+iid].c;//cout<<s2[i].a<<' '<<s2[i].c<<' ';
        }
        up=n-iid;
    }
    r=up;
    while(l<id&&r>=1){
        if(s1[l].a==s2[r].a){
            if(s1[l].c!=s2[r].c) ans+=s1[l].a;
            //cout<<s1[l].c<<' '<<s2[r].c<<' ';
            l++, r--;
            //cout<<l<<' '<<r<<' '<<ans<<' ';
        }
        else if(s1[l].a<s2[r].a){
            if(s1[l].c!=s2[r].c){
                ans+=s1[l].a;
            }
            s2[r].a-=s1[l].a;
            l++;
            //cout<<ans<<' ';
        }
        else{
            if(s1[l].c!=s2[r].c){
                ans+=s2[r].a;
            }
            s1[l].a-=s2[r].a;
            r--;
            //cout<<ans<<' ';
        }
    }
    cout<<ans;

    return 0;
}
