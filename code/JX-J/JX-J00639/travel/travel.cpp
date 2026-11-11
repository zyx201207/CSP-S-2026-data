#include<bits/stdc++.h>
using namespace std;
int n1, n2;
string s1, s2;
char a[5] = {'A','B','C','D','F'};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n1>>s1>>n2>>s2;
    if(n1 = n2) cout<<1; else cout<<0;
    for(int i=1; i<=3; i++){
            if(s1[1]==s2[1] && s1[2]==s2[2] && s1[3]==s2[3]){cout<<"0000"; return 0;}
        if(i=1){
            if(s1[i]!=s2[i]) cout<<0;
            else{
                if(s1[i+1]!=s2[i+1]) cout<<0;
                else cout<<1;
            }
        }
        if(i=3){
            for(int j=1; j<=5; j++){
                if(s1[i]==a[j]){
                    if(s2[i]==a[j+1] && s1[i]!='C') cout<<1;
                    if(s2[i]==a[j-1] && s1[i]!='D') cout<<1;
                    else cout<<0;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
