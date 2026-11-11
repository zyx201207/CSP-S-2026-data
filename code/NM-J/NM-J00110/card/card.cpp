#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],cnt[3005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    if(n>5000){
        int x=1;
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1])x=i+1;
        }
        for(int i=x;i<=n;i++){
            cnt[a[i]]++;
        }
        for(int i=1;i<=m;i++){
            cout<<cnt[i]<<' ';
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int>st;
        vector<bool>f(m+5,0);
        for(int j=i;j<=n;j++){
            while(f[a[j]]&&!st.empty()){
                //if(st.top()==a[j])f[a[j]]=0;
                f[st.top()]=0;
                st.pop();
            }
            st.push(a[j]);
            f[a[j]]=1;
        }
        while(!st.empty()){
            cnt[st.top()]++;
            //cout<<st.top()<<' ';
            st.pop();
        }
        //cout<<"\n";
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }

    return 0;
}
