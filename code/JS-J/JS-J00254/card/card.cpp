#include<bits/stdc++.h>
using namespace std;
const int N =5e5 +10,M=3e5 +10;
int n,m;
int a[N];
int cnt[M];
int cntA[M];
bool inst[M];
bool A=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i-1]>a[i]){
            A=0;
        }
    }
    if(A){
        for(int i=1;i<=n;i++){
            cntA[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            cntA[a[i]]--;
            if(cntA[a[i]]==0){
                cnt[i]=i;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<cnt[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        fill(inst+1,inst+m+1,0);
        stack<int>s;
        for(int j=i;j<=n;j++){
            if(inst[a[i]]){
                while(s.top()!=a[i]){
                    inst[s.top()]=0;
                    s.pop();
                }
                inst[a[i]]=1;
            }else{
                s.push(a[i]);
                inst[a[i]]=1;
            }
        }
        while(!s.empty()){
            cnt[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
