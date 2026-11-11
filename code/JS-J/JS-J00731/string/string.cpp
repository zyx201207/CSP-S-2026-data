#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
char a;
long long num,b,nb,mid,nam;
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b>>a;
        num+=b;
        for(int j=nb+1;j<=num;j++){
            s[j]=a;
        }
        nb=b;
    }
    nam=0;
    if(num%2==0){
        mid=num/2;
        for(int i=1;i<=mid;i++){
            s1[i]=s[i];
        }
        for(int i=mid+1;i<=num;i++){
            s2[i-mid]=s[i];
        }
        for(int i=1;i<=mid;i++){
            if(s1[i]!=s2[mid-i+1]){
                nam++;
            }
        }
    }else{
        mid=num/2+1;
        for(int i=1;i<mid;i++){
            s1[i]=s[i];
        }
        for(int i=mid+1;i<=num;i++){
            s2[i-mid]=s[i];
        }
        for(int i=1;i<mid;i++){
            if(s1[i]!=s2[mid-i]){
                nam++;
            }
        }
    }
    cout<<nam<<endl;
}
