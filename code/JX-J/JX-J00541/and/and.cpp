#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,tzn;
int a[300005];
void teyi(){
    int sum=-1e15;
    for(int i=1;i<=n;i++){
        sum=max(sum,a[i]);
    }
    cout<<sum;
    return;
}
void teer(){
    int sum=-1e15;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            sum=max(sum,a[i]&a[j]);
        }
    }
    cout<<sum;
    return;
}
void tesan(){
    int sum=a[1];
    for(int i=2;i<=n;i++){
        sum&=a[i];
    }
    cout<<sum;
    return;
}
void tesi(){
    int ans=-1e15;
    for(int i=1;i<=n;i++){
        int sum=2147483648;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            sum&=a[j];
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return;
}
void dfs(int x,int y,int z){
    if(n-x+1<m-y)return;
    if(y==m){
        tzn=max(tzn,z);
        return;
    }
    for(int i=x+1;i<=n;i++){
        dfs(i,y+1,z&a[i]);
        dfs(i,y,z);
    }
}
void tewu(){
    dfs(0,0,2147483647);
    cout<<tzn;
}
void teliu(){
    dfs(0,0,2147483647);
    cout<<tzn;
}
void teqi(){
    sort(a+1,a+n+1);
    int sum=a[n],cnt=1;
    for(int i=n-1;i>=1;i--){
        if(cnt==m)break;
        cnt++;
        sum&=a[i];
    }
    cout<<sum;
    return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    bool flag=0,flag2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>4)flag=1;
        if(a[i]!=i-1)flag2=1;
    }
    if(m==1)teyi();
    else if(m==2)teer();
    else if(m==n)tesan();
    else if(m==n-1)tesi();
    else if(n<=30){
        dfs(0,0,2147483647);
        cout<<tzn;
    }
    else if(flag==0)tewu();
    else if(flag2==0)teliu();
    else teqi();
	return 0;
}
