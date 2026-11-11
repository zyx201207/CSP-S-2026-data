#include<bits/stdc++.h>
using namespace std;
int a[200005][30];
int v[30][200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int k=1;
        string s="";
        while(x!=0){
            if(x%2==0)s=s+'0';
            if(x%2==1)s=s+'1';
            x/=2;
        }
        for(int j=0;j<s.size();j++){
            a[i][j]=s[j]-'0';
        }
    }
    int kk=30;
    for(int i=29;i>=0;i--){
        int sum=0;
        if(kk==30){
            for(int j=1;j<=n;j++){
                if(a[j][i]==1){
                    sum++;
                    v[i][j]=1;
                }
            }
        }else{
            for(int j=1;j<=n;j++){
                if(v[kk][j]==1&&a[j][i]==1){
                    sum++;
                    v[i][j]=1;
                }
            }
        }
        if(sum>=m){
            kk=i;
            int q=1;
            for(int j=1;j<=i;j++)q=q*2;
            ans+=q;
        }
    }
    cout<<ans;
    return 0;
}
