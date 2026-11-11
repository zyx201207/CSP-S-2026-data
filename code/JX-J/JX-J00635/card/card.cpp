
#include <bits/stdc++.h>
using namespace std;

int s[10];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cn[m+1]={0};
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int p=1;p<=n;p++){
    string ans={ };
    for(int i=p;i<=n;i++){
        for(int j=p;j<i;j++){
            if(s[j]==s[i]){
                    ans={ };
                for(int z=p;z<j;z++) ans[z]=s[z];
            }
        }
        ans+=s[i];
    }
    for(int i=1;i<=ans.size();i++){
        cn[ans[i]]++;
    }
    }
    for(int i=1;i<=m;i++){
        cout<<cn[i]<<' ';
    }

    return 0;
}
