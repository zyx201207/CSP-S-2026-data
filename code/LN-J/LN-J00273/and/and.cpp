#include<bits/stdc++.h>
using namespace std;
char a[200005][32];
bool v[200005];
int n,m,b,s,c=1073741824;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b;
        int j=0;
        while(b){
            if(b%2==0){
                a[i][j]='0';
            }
            else{
                a[i][j]='1';
            }
            b/=2;
            j++;
        }
        for(;j<32;j++){
            a[i][j]='0';
        }
        v[i]=1;
    }
    for(int i=30;i>=0;i--){
        int q=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]=='1'&&v[j]==1){
                q++;
            }
        }
        if(q>=m){
            for(int j=1;j<=n;j++){
                if(a[j][i]=='0'){
                    v[j]=0;
                }
            }
            s+=c;
        }
        c/=2;
    }
    cout<<s;
    fclose("and.in");
    fclose("and.out");
    return 0;
}
