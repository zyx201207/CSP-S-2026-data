#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string tobin(int x){
    long long base=1<<30;
    string s="";
    while(base){
        if(x<base){
            s.push_back('0');
        }
        else{
            s.push_back('1');
            x-=base;
        }
        base>>=1;
    }
    return s;
}
long long todec(string s){
    long long base=1<<30;
    long long res=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            res+=base;
        }
        base>>=1;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<string> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(tobin(x));
        //cerr<<tobin(x)<<endl;
    }
    bool use[n+5];
    for(int pos=0;pos<31;pos++){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!use[i]&&a[i][pos]=='1'){
                cnt++;
            }
        }
        if(cnt>=m){
            for(int i=0;i<n;i++){
                if(!use[i]&&a[i][pos]=='0'){
                    use[i]=1;
                }
            }
        }
    }
    int i=0;
    long long ans=INT_MAX;
    for(int j=0;j<n&&i<m;j++){
        if(!use[j]){
            ans&=(todec(a[j]));
            //cerr<<todec(a[j])<<endl;
            i++;
        }
    }
    cout<<ans;
    return 0;
}
//RP++
