#include<bits/stdc++.h>
using namespace std;
string s[100000],s1[100000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,k,flag=0,num=0,sum=0;
    char a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k>>a;
        for(int j=flag;j<k+flag;j++){
            s[j]=a;
            }
        flag+=k;
        }
    for(int i=flag-1;i>-1;i--){
        s1[sum]=s[i];
        sum++;
    }
    for(int i=0;i<flag;i++){
        if(s[i]!=s1[i]){
            s[i]=s1[i];
            sum=0;
            for(int i=flag;i>0;i--){
                s1[sum]=s[i];
                sum++;
            }
            num++;
        }
    }
    cout<<num;
    return 0;
}
