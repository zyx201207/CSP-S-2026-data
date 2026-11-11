#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200001];
long long dp[200001];
long long num4=0,num3=0,num2=0,num1=0;
long long mx3=0,lst=0;
long long chi[21],tp=1;
void dfs(long long nw,long long ch,long long id){
    if(id==n+1){
        if(ch!=m){
            return;
        }
        else{
            mx3=max(mx3,nw);
            return;
        }
    }
    chi[tp]=id;
    tp++;
    dfs(nw&a[id],ch+1,id+1);
    tp--;
    dfs(nw,ch,id+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    long long mx=0;
    long long ax=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(i==1){
            ax=a[i];
        }
        else{
            ax&=a[i];
        }
        mx=max(mx,a[i]);
        if(a[i]==4){
            num4++;
        }
        if(a[i]==3){
            num3++;
        }
        if(a[i]==2){
            num2++;
        }
        if(a[i]==1){
            num1++;
        }
    }
    if(m==1){
        cout << mx << endl;
        return 0;
    }
    if(m==n){
        cout << ax << endl;
        return 0;
    }
    if(m==2){
        long long mx2=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i!=j){
                    mx2=max(mx2,a[i]&a[j]);
                }
            }
        }
        cout << mx2 << endl;
        return 0;
    }
    if(mx==4){
        if(num4>=m){
            cout << 4 << endl;
            return 0;
        }
        else if(num3>=m){
            cout << 3 << endl;
            return 0;
        }
        else if((num3+num2)>=m){
            cout << 2 << endl;
            return 0;
        }
        else if((num3+num1)>=m){
            cout << 1 << endl;
            return 0;
        }
        else{
            cout << 0 << endl;
            return 0;
        }
    }
    if(n<=20){
        for(int i=1;i<=n;i++){
            dfs(a[i],0,i);
        }
        cout << mx3 << endl;
        return 0;
    }
    return 0;
}
