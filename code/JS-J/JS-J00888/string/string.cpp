#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
string a;
struct node{
    int cnt;
    char s;
}p[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].cnt>>p[i].s;
    }
    if(n==1){
        cout<<"0";
    }else if(n==2){
        if(p[0].s==p[1].s){
            cout<<0;
            return 0;
        }else if(p[0].cnt<p[1].cnt){
            cout<<p[0].cnt;
        }else if(p[0].cnt==p[1].cnt){
            cout<<p[0].cnt;
        }else{
            cout<<p[1].cnt;
        }
    }else{
        int flag=0;
        for(int i=1;i<n;i++){
            if(p[i].s!=p[i-1].s)flag++;
        }
        if(flag==0){
            cout<<0;
        }else{
            int ans=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<p[i].cnt;j++){
                    a=a+p[i].s;
                }
            }
            int l=a.size();
            for(int i=0;i<l/2;i++){
                 if(a[i]!=a[l+1-i]){
                    ans++;
                 }
            }
            cout<<ans;
        }
    }
    return 0;
}
/*
4
1 a
1 b
1 a
1 c
abac
62
*/
