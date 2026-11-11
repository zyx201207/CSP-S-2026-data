#include<bits/stdc++.h>
using namespace std;
int da[200005][35];
long long a[200005];
vector<int> b[35];
int n,m,st,maxx;long long ans;
bool Find(int y,int x){
    for(int i=0;i<(int)b[maxx].size();i++)if(b[maxx][i]==b[y][x])return 1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(m==1){cout<<a[0];return 0;}
    for(int i=0;i<n;i++){
        int j=1;
        while(a[i]){
            da[i][j++]=a[i]%2;
            a[i]>>1;
            b[j-1].push_back(i);

        }
        st=max(st,j-1);
    }
    int c=0;
    for(int i=st;i>0;i--){
        if((int)b[i].size()<m)continue;
        maxx=i;c++;
        if(c!=1){
            vector<int> v2;
            for(int j=0;j<(int)b[i].size();j++){
                if(Find(i,j))v2.push_back(j);
                if(v2.size()==m){
                    for(int k=0;k<(int)v2.size();k++)ans&=v2[k];
                    cout<<ans<<endl;
                    return 0;
                }
                else
                  if(i==1)
                    for(int k=1;k<=m;k--)ans&=v2[(int)v2.size()-k];
            }
        }
    }
    return 0;
}
