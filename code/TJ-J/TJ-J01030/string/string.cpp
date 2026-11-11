#include<bits/stdc++.h>
using namespace std;
int trypea[30];
vector <int> s,number1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int suma=0,n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int sum=0,letter;
        cin>>sum;
        number1[i]=sum;
        suma+=sum;
        cin>>letter;
        s[i]=letter;
        trypea[letter-97]+=sum;
    }
    int maxn=0,sition=0;
    for(int i=0;i<=26;i++){
        maxn=max(trypea[i],maxn);
        if(trypea[i]>=0){
            sition++;
        }
    }
    if(sition==0||sition==1){
        cout<<"0";
    }
    if(sition==2){
        cout<<suma-maxn;
    }
}
