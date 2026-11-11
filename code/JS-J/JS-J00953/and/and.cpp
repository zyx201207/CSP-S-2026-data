#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool cd[2000010];
int n,m;
long long ans;
void ff(int x,bool f,long long k){
    if(x==n-1){
        ans=max(ans,k);

        return;
    }
    if(f==1){
        ff(x+1,0,k);
    }
    ff(x+1,1,k&a[x]);
}
int b[1010];
void solve(int now,int let){
    if(now>n) return;
    if(now==n&&let==0){
        long long t=b[0]&b[1];
        for(int i=2;i<=m;i++){
            t=t&b[i];
        }
        ans=max(ans,t);
        return;
    }
    if(let>0){
        b[let]=a[now];
        solve(now+1,let-1);
    }
    solve(now+1,let);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int c=0;
    long long maxa=-1;
    int cnt=0;
    for(int i=0;i<=20;i++){
        cd[(int)pow(2,i)-1]=1;
    }
    int cr=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(cd[a[i]]!=1){
            cr=1;
        }
        cnt++;
        maxa=max(maxa,a[i]);
        //cout<<"difasdfa"<<cnt<<endl;
    }
    //cout<<"difasdfa"<<cnt;
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }

    if(m==2){
        long long maxx=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
        return 0;
    }
    if(m==n){
        c=a[1]&a[2];
        for(int i=3;i<=n;i++){
            c=c&a[i];
        }
        cout<<c;
        return 0;
    }
    if(m==n-1){
        ff(1,1,pow(2,20)-1);
        cout<<ans;
        return 0;
    }
    if(cr==0){
        cout<<a[n-m+1];
        return 0;
    }
    if(n<=30){
        solve(0,m);
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
//001
//010
//011
//100
//101
/*
将各题最终提交的 C++ 源文件直接保存在这个文件夹内,文件名及大小写严格按题
面要求填写,扩展名为 .cpp。例如,若题目要求源文件名为 problem.cpp
*/
