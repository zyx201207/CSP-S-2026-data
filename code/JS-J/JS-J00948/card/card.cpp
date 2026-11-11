#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500007];
char s[500007];
map<int,int>mp;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int k=0;k<n;k++){
        cnt=0;
        s[0]=a[k]+'0';
        for(int i=1+k;i<n;i++){
            cnt++;
            s[cnt]=a[i]+'0';
            for(int j=0;j<=cnt;j++){
                if(s[j]==a[i]+'0'){
                    cnt=j;
                    break;
                }
            }
        }
        for(int i=0;i<=cnt;i++){
            mp[s[i]-'0']++;
            //cout<<s[i];
        }
        //cout<<endl;
    }

    for(int i=1;i<=m;i++){
        cout<<mp[i]<<" ";
    }
    return 0;
}
