#include<bits/stdc++.h>
using namespace std;
long long a[2001];
int n,m;
int f(int x,int y){
    int num1,num2;
    int s;
    if(m==1) return a[x];
    for(int i=1;i<=n;i++){
        if(i!=x){
            num1=f(i,m-1);
            num2=a[i]&num1;
        }
        if(num2>=s) s=num2;
    }
    return s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("ans.our","w",stdout);
    cin>>n>>m;
    priority_queue<long long>q;
    long long sum=1;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.push(a[i]);
        sum=sum&a[i];
        if(a[i]!=i-1)flag=false;
    }
    if(m==1){
        cout<<q.top();
        return 0;
    }else if(m==n){
        cout<<sum;
        return 0;
    }else if(m==2){
        int m_=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i]&a[j]>=m_)m_=a[i]&a[j];
            }
        }
        cout<<m_;
        return 0;
    }else if(m==n-1){
        int m_=0;
        for(int i=1;i<=n;i++){
            int num=a[i];
            for(int j=1;j<=n;j++){
                if(j!=i)num=num&a[j];
            }
            if(num>=m_)m_=num;
        }
        cout<<m_;
        return 0;
    }else if(flag){
        cout<<q.top();
        return 0;
    }else if(n<=20){
        int ans=0;
        for(int i=1;i<=n;i++){
            int num=f(i,m-1);
            if(num>=ans) ans=num;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
