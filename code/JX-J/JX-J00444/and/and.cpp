#include <bits/stdc++.h>
using namespace std;

long long n,m,a[100000];
string ans[100000];

string pd(string s1,string s2){
    string ans;
    for(int i=0;i<max(s1.size(),s2.size());i++){
        if(s1[i]=='1' and s1[i]==s2[i]){
            ans+='1';
        }else ans+='0';
    }
    return ans;
}

string er(int a){
    string s;
    while(a!=0){
        char c=a%2+'0';
        s=c+s;
        a/=2;
    }
    return s;
}

int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int k=1;
    for(int i=1;i<=n-m;i++){

        ans[k]=pd(er(i),er(i+1));
        k++;
    }
    sort(ans+1,ans+k);
    cout<<ans[k-1];
    return 0;
}
