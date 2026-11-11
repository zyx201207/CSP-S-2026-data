#include<bits/stdc++.h>
using namespace std;
stack<int> st;
bool ha[300001];
int ans[300001];
vector<int> sa;
int n,m,a,t;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    //cout<<"*\n";
    cin>>n>>m;
    sa.push_back(0);
    //cout<<"*\n";
    for(int i=1;i<=n;i++){
        cin>>a;
        sa.push_back(a);
    }
    //cout<<"*\n";
    for(int x=1;x<=n;x++){
        for(int i=x;i<=n;i++){
            a=sa[i];
            if(ha[a]!=0){
                while(1){
                    t=st.top();
                    if(t==a) break;
                    st.pop();
                }
            }
            else{
                st.push(a);
                ha[a]=1;
            }
        }
        for(int i=1;i<=m;i++){
            if(ha[i]!=0) ans[i]++;
        }
        while(!st.empty()) st.pop();
        memset(ha,0,sizeof(ha));
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}