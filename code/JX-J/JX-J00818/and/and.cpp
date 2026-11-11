#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
int n,m,maxans=INT_MIN;
cin>>n>>m;
int a[n+5];
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        int x=a[i],y=a[j],ans=0;
        string xs="",ys="",xxs="",yys="",anse="";
        while(x>0){
            xs+=x%2+'0';
            x/=2;
        }
        while(y>0){
            ys+=y%2+'0';
            y/=2;
        }
        for(int k=xs.size();k>=0;k--){
            xxs+=xs[k];
        }
        for(int l=ys.size();l>=0;l--){
            yys+=ys[l];
        }
        int jjs=xxs.size(),wjw=yys.size();
        for(int k=1;k<=abs(jjs-wjw);k++){
            if(xxs.size()<yys.size()){
                xxs.insert(0,"2");
            }
            if(xxs.size()>yys.size()){
                yys.insert(0,"2");
            }
        }
        for(int k=1;k<xxs.size();k++){
            if(xxs[k]=='1'&&yys[k]=='1'){
                anse+="1";
            }
            else{
                anse+="0";
            }
        }
        for(int k=0;k<anse.size();k++){
            int er=1;
            for(int l=1;l<=4-k-1;l++){
                er*=2;
            }
            ans+=(anse[k]-'0')*er;
        }
        if(ans>maxans) maxans=ans;
    }
}
cout<<maxans;
return 0;
}
