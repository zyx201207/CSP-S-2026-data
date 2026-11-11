//16~17:2*5=10
//m+1 sides
#include<bits/stdc++.h>
using namespace std;
int top(int a,int b){return a%b?a/b+1:a/b;}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;cin>>c>>t;
    while(t--){
        int n,k;cin>>n>>k;int m_1=n/2+1;
        int t=top(m_1,2*k);
        if(t%2||m_1<=2+4*k)t++;
        cout<<t<<'\n';
        for(int i=1;i<n;i++)cin>>c>>k;
    }
    return 0;
}
