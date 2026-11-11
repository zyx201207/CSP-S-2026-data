#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=1e6;
long long c[N];
char ch[N];
string frt;
long long n,ans;
long long judge(string s){
    for(int i=0,j=s.size()-1;i<j;i++,j--){
        if(s[i]==s[j]) continue;
        return 0;
    }
    return 1;

}
long long change(string s){
    int cnt=0;
    int i=0,j=s.size()-1;
    while(!judge(s)&&i<j){
        if(s[j]!=s[i]){
            s[j]=s[i];
            cnt++;
            i++;
            j--;
        }
        else {
            i++;
            j--;
        }

    }
    return cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>ch[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c[i];j++){
            frt+=ch[i];
        }
    }
  //  cout<<frt<<endl;
    //for(int i=0;i<frt.size();i++) cout<<i<<' '<<frt[i]<<endl;
    if(judge(frt)) cout<<0;
    ans=change(frt);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
