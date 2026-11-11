#include <bits/stdc++.h>

using namespace std;
string str;
long long N;
long long ans1,ans2,gdb=1;
long long x[200001][2];
long long min1(){
    long long t=1e9;
    for(long long i=1;i<=N;i++){
        if(x[i][0]<t){
            t=x[i][0];
        }
    }
    return t;
}
int main()
{
//    freopen("string.txt","r",stdin);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>N;
    for(long long I=1;I<=N;I++){
        long long a;char c;
        cin>>a>>c;
        x[I][0]=a;
        x[I][1]=c;
    }
    for(long long i=min1();i>=2;i--){
        bool u=1;
        for(long long j=1;j<=N;j++){
            if(x[j][0]%i!=0){
                u=0;
            }
        }
        if(u){
            gdb=i;
            for(long long k=1;k<=N;k++){
                x[k][0]/=gdb;
            }
            break;
        }
    }
    for(long long i=1;i<=N;i++){
        for(long long j=1;j<=x[i][0];j++){
            str+=x[i][1];
        }
    }
    reverse(str.begin(),str.end());
    string str1=str.substr(0,str.size()/2);
    string str2=str.substr(str.size()/2+str.size()%2);
    reverse(str.begin(),str.end());
    if(str1==str2){
        cout<<'0';return 0;
    }
    for(long long i=0;i<=str1.size()-1;i++){
        ans1+=(str1[i]!=str[i]);
    }
    for(long long i=str.size()/2+str.size()%2;i<=str.size()-1;i++){
        ans2+=(str2[i]!=str[i]);
    }
    if(ans1>ans2){
        swap(ans1,ans2);
    }
    long long pq=ans1;pq*=gdb;
    cout<<pq;
    return 0;
}
