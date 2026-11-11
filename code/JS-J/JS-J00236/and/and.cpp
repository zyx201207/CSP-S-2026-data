#include<bits/stdc++.h>
using namespace std;
long long a[200010];
string s[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    string anss="000000000000000000000000000000";
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]="000000000000000000000000000000";
    }
    for(int i=1;i<=n;i++){
        int j=0;
        while(a[i]!=0){
            s[i][j]=a[i]%2+'0';
            a[i]/=2;

            j++;
        }
    }

    for(int i=29;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(s[j][i]=='1') cnt++;
        }
        if(cnt>=m){
            for(int j=1;j<=n;j++){
                if(s[j][i]=='0') {
                    s[j]="00000000000000000000000000000000";
                }
            }
            anss[i]='1';
        }
        else{
            anss[i]='0';
        }

    }
    for(int i=0;i<30;i++){
        ans+=pow(2,i)*(anss[i]-'0');
    }

    cout<<ans;
    return 0;
}

