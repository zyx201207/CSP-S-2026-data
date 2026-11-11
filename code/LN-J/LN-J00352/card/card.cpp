#include<bits/stdc++.h>
using namespace std;
stack<int> x;
int s[500005],t[300005],t1[300005],a[500005],cnt=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,k;
    cin>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=m;j>=i;j--){
            x.push(a[j]);
        }
        while(!x.empty()){
            int a1=x.top(),f=0;
            //cout<<a1<<endl;
            for(int j=1;j<=cnt;j++){
                if(s[j]==a1){
                    cnt=j;
                    f=1;
                    break;
                }
            }
            if(f==0){
                s[++cnt]=a1;
            }
            x.pop();
        }
        for(int j=1;j<=cnt;j++){
            t[s[j]]++;
            s[j]=0;
        }
        //cout<<endl;
        cnt=0;
    }
    for(int i=1;i<=k;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
