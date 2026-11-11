#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    char a[n];
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    long long ans[m+5]={};
    for(int i=0;i<n;i++){
        vector<char> b;
        long long c[m+5]={};
        long long d[m+5]={};
        for(int j=i;j<n;j++){
            b.push_back(a[j]);
            if(c[a[j]-'0']!=0){
                    c[a[j]-'0']=0;
                int bn=b.size();
                for(int i=d[a[j]-'0'];i<bn-1;i++){
                    b.pop_back();
                }
            }
            c[a[j]-'0']++;
        }
        for(int i=0;i<b.size();i++){
            ans[b[i]-'0']++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
