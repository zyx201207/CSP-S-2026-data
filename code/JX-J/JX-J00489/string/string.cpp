#include<bits/stdc++.h>
using namespace std;
struct node{
    int a;
    string c;
}b[200010];
bool ishui(string s){
    string s1="";
    for(int i=s.size()-1;i>=0;i--){
        s1+=s[i];
    }if(s1==s){
        return true;
    }else{
        return false;
    }
}
string fan(string s){
    string s1="";
    for(int i=s.size()-1;i>=0;i--){
        s1+=s[i];
    }return s1;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int sum=0;
    int ans=10000000;
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    string s="";
    for(int i=1;i<=n;i++){
        cin>>b[i].a;
        cin>>b[i].c;
        for(int j=1;j<=b[i].a;j++){
            s+=b[i].c;
        }
    }
    if(ishui(s)){
        cout<<0;
        return 0;
    }
    if(n==2){
        cout<<min(b[1].a,b[2].a);
        return 0;
    }
    if(n%2==1){
        int d=s.size();
        for(int i=1;i<=n;i+=2){
            sum=0;
            for(int j=d/2-i/2;j<=d/2+i/2;j++){
                if(j!=d/2){
                    if(s[j]!=s[d/2*2-j]){
                        sum++;
                    }
                }
            }
            string s1=s.substr(0,d/2-i/2);
            string s2=fan(s1);
            string s3=s.substr(d/2+i/2+1,d);
            for(int j=0;j<s2.size();j++){
                if(s2[j]!=s3[j]){
                    sum++;
                }
            }ans=min(ans,sum);
        }
        cout<<ans;
    }else{
        int d=s.size();
        for(int i=0;i<=n;i+=2){
            sum=0;
            for(int j=d/2-i/2;j<=d/2+i/2-1;j++){
                if(j!=d/2){
                    if(s[j]!=s[d-1-j]){
                        sum++;
                    }
                }
            }
            string s1=s.substr(0,d/2-i/2);
            string s2=fan(s1);
            string s3=s.substr(d/2+i/2,d);
            for(int j=0;j<s2.size();j++){
                if(s2[j]!=s3[j]){
                    sum++;
                }
            }ans=min(ans,sum);
        }
        cout<<ans;
    }
    return 0;
}
