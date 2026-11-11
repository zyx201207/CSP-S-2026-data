#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    string ss[m];
    int ssi=0;
    for(int i=n-1;i>=n-1-m;i--){
        int num=a[i];
        string s;
        while(num>0){
            if(num%2==1) s+='1';
            else s+='0';
            num/=2;
        }
        ss[ssi]=s;
        ssi++;
    }
    string sss=ss[0];
    for(int i=0;i<m-1;i++){
        string s=ss[i+1];
        for(int j=0;j<ss[i].length();j++){
            if(sss[j]=s[j]) sss.replace(j,'1');
            else sss.replace(j,'0');
        }
    }
    int sum=0;
    for(int i=0;i<sss.length();i++){
        if(sss[i]=='1'){
            int e=pow(2,i);
            sum+=e;
        }
    }
    cout<<sum;
    return 0;
}
