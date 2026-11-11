#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010];
string s="";
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        s.clear();
        int k=0;
        for(int j=i;j<=n;j++){
            char c=a[j]+48;
            if(!s.empty()&&s.find(c)!=k&&s.find(c)!=-1){
                s.erase(0);
            }
            s+=c;
            k++;
        }
        for(int j=0;j<s.size();j++) b[s[j]-'0']++;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    cout<<endl;
    return 0;
}
