#include<bits/stdc++.h>
using namespace std;

int n,cnt=0;
string s="";
int f1[100010];
int f2[100010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        string s1;

        int a;
        string c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s1+=c;
        }
        s+=s1;
    }
    int h=s.size();
    int f;
    bool v=1;
    if(h%2){
        f=h/2+1;
        v=0;
    }else{
        f=h/2;
    }
    int ans=-111,ans2=-111;

    for(int i=0;i<f;i++){
        int j=s[i]-'0';
        f1[j]++;
        ans=max(ans,f1[j]);
    }
    int q,w;
    for(int i=0;i<300;i++){
        if(f1[i]==ans){
            q=i;
        }
    }
    if(!v){

        for(int i=f+1;i<h-1;i++){
            int j=s[i]-'0';
            f2[j]++;
            ans2=max(ans2,f2[j]);

        }
    }else{
        for(int i=f+1;i<h;i++){
            int j=s[i]-'0';
            f2[j]++;
            ans2=max(ans2,f2[j]);

        }

    }
    for(int i=0;i<100;i++){
        if(f2[i]==ans2){
            w=i;
        }
    }
    if(ans>ans2){
        for(int i=f;i<h;i++){
            if(s[i]!=s[f-i+f]){
                cnt++;
            }

        }

    }else{
        for(int i=0;i<f;i++){
                if(s[i]!=s[i-f]){
                cnt++;
            }

        }

    }
    cout<<cnt;



    return 0;

}
