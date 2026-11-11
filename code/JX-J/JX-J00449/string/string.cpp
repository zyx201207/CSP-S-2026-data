#include<bits/stdc++.h>
using namespace std;

struct node{
    int a;
    char c;
};

string f(node a){
    string ans="";
    for(int i=0;i<a.a;i++){
        ans+=a.c;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    node s[n];
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>s[i].a>>s[i].c;
        cnt+=s[i].a;
    }
    int ans=0;
    int i=0,j=n-1;
    string temp_l="";
    string temp_r="";
    while(i-1<j){
        int h=min(temp_l.size(),temp_r.size());
        for(int k=0;k<h;k++){
            if(temp_l[k]!=temp_r[temp_r.size()-k-1]){
                ans++;
                temp_l.erase(k,1);
                temp_r.erase(temp_r.size()-k-1,1);
            }
        }
        if(temp_l.size()>temp_r.size()){
            temp_r=f(s[j])+temp_r;
            j--;
        }else{
            temp_l+=f(s[i]);
            i++;
        }
    }
    //temp_l+=f(s[j]);
    //temp_l+=temp_r;
    for(int i=0;i<temp_l.size();i++){
        if(temp_l[i]!=temp_r[temp_r.size()-i-1]){
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
