#include<bits/stdc++.h>
using namespace std;
string s;
char a[500050];
int b[500050];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int num=1;
        for(int j=i;j<=n;j++,num++){
            if(s.find(a[j])){
                int star=s.find(a[j]);
                for(int k=star;k<num;k++){
                    s[k]=' ';
                    num--;
                }
            }
            s[num]=a[j];
        }
        for(int i=1;i<=m;i++){
            if(s.find(to_string(i))) b[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
