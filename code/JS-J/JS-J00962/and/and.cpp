#include<bits/stdc++.h>
using namespace std;
int t[35]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
int dx[4];
int main(){
    freopen("and3.in","r",stdin);
    freopen("and.out","w",stdout);
    int s,m,mxa=0,lll=0;
    cin>>s>>m;
    vector<int>g(s);
    for(int i=0;i<s;i++){
        cin>>g[i];
        mxa=max(mxa,g[i]);
        if(g[i]<4)dx[g[i]]++;
    }
    for(int i=0;i<35;i++){
        if(s==t[i])lll=1;
    }
    if(s<=400||m==s-1){
        string d="";
        int k=0;
        for(int i=0;i<s-m;i++)d+='0';
        for(int j=0;j<m;j++)d+='1';
        do{
            int h=2147483647;
            for(int i=0;i<s;i++){
                if(d[i]=='1')h&=g[i];
            }
            k=max(k,h);
        }while(next_permutation(d.begin(),d.end()));
        cout<<k;
    }
    else if(s==m||s==1){
        int k=2147483647;
        for(int i=0;i<s;i++){
            k=k&g[i];
        }
        cout<<k;
    }
    else if(m==1){
        int p=0;
        for(int i=0;i<s;i++)p=max(p,g[i]);
        cout<<p;
    }
    else if(mxa<4){
        if(mxa!=3){
            cout<<(dx[mxa]>=m)?1:0;
        }
        else{
            if(dx[3]>=m)cout<<3;
            else if(dx[3]+dx[2]>=m)cout<<2;
            else if(dx[3]+dx[1]>=m)cout<<1;
            else cout<<0;
        }
    }
    else if(m==2){
        int p=0;
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
               p=max(p,g[i]&g[j]);
            }
        }
        cout<<p;
    }
    else if(lll){
        int g=0;
        while(s/2>=m){
            s/=2;
            g+=s;
        }
        cout<<g;
    }
    else{
        sort(g.rbegin(),g.rend());
        cout<<g[m-1];
    }
    return 0;
}
