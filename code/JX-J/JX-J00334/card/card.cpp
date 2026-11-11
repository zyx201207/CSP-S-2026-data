#include<bits/stdc++.h>

using namespace std;
stack<int>s;
long long cn=1,n,m,a[555555],cnt[555555],now[555555];
int main(){


//freopen("card.in","r",stdin);
//freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}

for(int i=1;i<=n;i++){
        while(!s.empty()){
            s.pop();
        }

int cn[555555]={};
    for(int j=i;j<=n;j++){
if(cn[a[j]]!=0){
    while(s.top()!=a[j]){
            cnt[s.top()]--;
    cn[s.top()]--;
        s.pop();
    }
    cnt[s.top()]--;
    cn[s.top()]--;
        s.pop();
}

s.push(a[j]);
cn[a[j]]=1;
cnt[a[j]]++;
    }
}

for(int i=1;i<=m;i++){
    cout<<cnt[i]<<" ";
}
return 0;
}
