#include<bits/stdc++.h>
using namespace std;
struct fw{
    int a,b;
};
int n;
vector<fw> zhao(string a){
    vector<fw>r(n);
    int num=0;
    for(int i=a.size()-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
            if(a[i]==a[j]){
                fw n;
                n.a=j,n.b=i;
                r[num]=n;
                num++;
            }
        }
    }
    return r;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>n>>m;
    string a(n,' ');
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<fw>b=zhao(a);
    int num=0;
    for(int i=0;i<n;i++){
        int num1=0;
        vector<int>c(n);
        for(int j=i;j<a.size()-1;j++){
            if(a[j]==i){
                num1++;
                c[num1-1]=j;
            }
        }
        int n1=b.size()-1;
        while(b[n1].a>=i){
            for(int j=0;j<=c.size()-1;j++){
                if(c[j]!=-1){
                    if(c[j]>b[n1].a&&c[j]<b[n1].b){
                        c[j]=-1;
                        num1--;
                    }
                }
            }
        }
        num+=num1;
    }
    cout<<num;
}
