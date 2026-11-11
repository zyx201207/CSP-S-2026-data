#include<bits/stdc++.h>
using namespace std;
vector<string> s(200005,"000000000000000000000000000000");
bool cmp(string a,string b){
    if(a==b){
        return 0;
    }
    for(int i=0;i<30;i++){
        if(a[i]=='1'&&b[i]=='0'){
            return 1;
        }
        else if(a[i]=='0'&&b[i]=='1'){
            return 0;
        }
    }
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int ma=0,c8;
    for(int i=1;i<=n;i++){
        int c;
        cin>>c;
        ma=max(ma,c);
        c8=(i==1)?c:c8&c;
        int d=30;
        while(c!=0){
            s[i][--d]=int(c&1)+'0';
            c>>=1;
        }
    }
    if(m==1){
        cout<<ma;
        return 0;
    }
    if(m==n){
        cout<<c8;
        return 0;
    }
    sort(s.begin()+1,s.begin()+n+1,cmp);
    int ans=0,under=n;
    bool l=1;
    for(int i=0;i<30;i++){
        if(s[1][i]==0&&l){
            continue;
        }
        else{
            l=0;
        }
        int sum=0;
        bool f=1;
        for(int j=1;j<=under;j++){
            if(s[j][i]=='0'){
                if(sum>=m){
                    ans+=1<<(29-i);
                    under=j-1;
                    f=0;
                }
            }
            else{
                sum++;
            }
        }
        if(sum>=m&&f){
            ans+=1<<(29-i);
        }
    }
    cout<<ans;
    return 0;
}
