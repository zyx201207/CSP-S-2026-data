#include<bits/stdc++.h>
#define int long long
using namespace std;
const int L=2e6+10;
int c,t,n,d,x[L],l[L],r[L];
deque<int> dq;
void slv1(){
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>x[i];
        if(n<=2){
            cout<<"0\n";
            continue ;
        }
        int ks=d/(x[2]-x[1]);
        if(ks<=1 or ks*2>n){
            cout<<"0\n";
            continue ;
        }
        cout<<n-ks*2+1<<endl;
    }
}
void slv2(){
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>x[i];
        l[1]=1;
        dq.push_back(1);
        for(int i=2;i<=n;++i){
            while(!dq.empty() and x[i]-x[dq.front()]>d){
                r[dq.front()]=i-1;
                //cout<<dq.front()<<" "<<r[dq.front()]<<endl;
                dq.pop_front();
            }
            dq.push_back(i);
            l[i]=dq.front();
        }
        while(!dq.empty()){
            r[dq.front()]=n;
            dq.pop_front();
        }
        int ins=0;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if(r[i]-l[j]==1 and r[i]<j) ++ins;
                //if(r[i]-l[j]>=1) ++ins;
            }
        }
        cout<<ins<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11 or c==12) slv1();
    else slv2();
    return 0;
}
/*
0 1
6 3
3 6 9 12 15 18
*/
