#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,m,k;
int a[N];
int ans[N];
string s;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        k=max(k,a[i]);
    }

    for(int i=1;i<=n;i++){
        s="";
        for(int j=i;j<=n;j++){
            if(s.find(a[j]+'0')==-1){
                s+=a[j]+'0';
            }else{
                s=s.substr(0,s.find(a[j]+'0'));
                s+=a[j]+'0';
            }
            cout<<s<<endl;
        }
        for(int i=0;i<=n;i++){
            ans[s[i]-'0']++;
        }
    }

    for(int i=1;i<=k;i++){
        if(ans[i]!=0) cout<<ans[i]<<" ";
    }
    return 0;
}
