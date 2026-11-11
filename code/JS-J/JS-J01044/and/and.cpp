#include<bits/stdc++.h>
using namespace std;
string stk[1001];
int a[10001];
string erj(int n){
    string str,st;
    str="";
    st="";
    while(n!=0){
        str+=char(n%2+int('0'));
        n/=2;
    }
    for(int i=str.size()-1;i>=0;i--){
        st+=str[i];
    }
    return st;
}
int sum(int m,int n){
    int s=0;
    int k=1;
    for(int i=min(stk[m].size(),stk[n].size())-1;i>=0;i--){
        if(stk[n][i]==1 && stk[m][i]==1) s+=k;
        k*=2;
    }
    return s;
}
int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>a[i];
    stk[i]=erj(a[i]);
  }
  long long maxn=0;
  if(m==1){
    for(int i=0;i<n;i++){
        if(maxn<a[i]) maxn=a[i];
    }
  }
  else{
    for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
          if(sum(i,j)>maxn) maxn=sum(i,j);
       }
    }
  }
  cout<<maxn;
  return 0;
}
