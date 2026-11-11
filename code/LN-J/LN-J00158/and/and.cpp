#include<bits/stdc++.h>
using namespace std;

string two(int a){
    string p;
    while(a>0){
        p+=a%2+'0';
        a/=2;
    }
    return p;
}

int ten(string a){
    int p=0,s=a.size(),k=1;
    if(a=="0"){
        return 0;
    }
    for(int i=s-1;i>=0;i--){
        p+=(a[i]-'0')*k;
        k*=2;
    }
    return p;

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,mx=-1;
    cin>>n>>m;
    int a[n+1];
    string st[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        st[i]=two(a[i]);
        mx=max(a[i],mx);
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==2){
        string o;
        int g=-1;
        for(int i=0;i<n-1;i++){

            for(int j=i+1;j<n;j++){
                if(a[i]<=a[j]){
                    for(int k=st[i].size()-1;k>=0;k--){

                        if(st[i][k]=='1'&&st[j][k]=='1'){
                            o+='1';
                        }else{
                            o+='0';
                        }
                    }
                }else{
                    for(int k=st[j].size()-1;k>=0;k--){

                        if(st[i][k]=='1'&&st[j][k]=='1'){
                            o+='1';
                        }else{
                            o+='0';
                        }
                    }
                }
                g=max(g,ten(o));
                o="";
            }
        }
        cout<<g;

    }

    return 0;
}
