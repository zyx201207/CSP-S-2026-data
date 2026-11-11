#include<bits/stdc++.h>
using namespace std;
int n,m,b[100000],c[100000];
string s;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        string s1=s;
        for(int j=i;j<n;j++){
            b[s1[j]]++;
            if(b[s1[j]]>1){
                for(int z=s1.find(s1[j]);z<j-1;z++){
                    s1[i]='0';
                }
                b[s1[j]]=1;
            }
        }
        for(int j=0;j<n;j++){
            c[(s[i]-'0')]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
