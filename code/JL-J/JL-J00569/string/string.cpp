#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
            cout<<0;
            return 0;
        }
    int a[n],b[30];//30->26 UK words
    long long k=0;
    string ss;
    string s;
    long long sum=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>ss[i];
        sum+=a[i];
        if(n==2 && ss[i]==ss[i-1] && i>1){
            cout<<0;
            return 0;
        }
    }
    int upo=0;
    for(int j=0;j<n;j++){
        for(int i=0;i<a[i];i++){
            s[upo]=ss[j];
            upo++;
        }
    }

    string s1[100010],s2[100010];
    if(sum%2!=0){
        int y=0;
        for(int i=0;i<sum/2;i++){
            s1[y]=s[i];
            y++;
        }
        y=0;
        for(int i=sum/2-1;i<=sum;i++){
            s2[y]=s[i];
            y++;
        }
    }
        else{
            int y=0;
        for(int i=0;i<=sum/2;i++){
            s1[y]=s[i];
            y++;
        }
        y=0;
        for(int i=sum/2+1;i<=sum;i++){
            s2[y]=s[i];
            y++;
        }
        }

   int kkk=0;
    for(int i=0;i<sum/2;i++){
     if(s1[i]!=s2[i]){
    kkk++;
       }

   }
   cout<<kkk;
    return 0;
}

