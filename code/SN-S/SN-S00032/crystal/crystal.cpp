#include<bits/stdc++.h>
using namespace std;
int a[50005];
int p[50005];
int n,m;
int slove (int start,int still){
int re = still;//剩余值
int now = start;
int step = 1;//现在在做第step步 
while(re>=step*p[now+1]&&now+1<=n){
re-=step*p[now+1];
step+=1;
now+=1;
} 
return step;
}

int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i = 0;i<n;i++){
cin>>a[i];
}
sort(a,a+n);
p[1]=a[1]-a[0];
for(int i =2;i<n;i++){
p[i]=a[i]-a[i-1];
}
int result = 1;



for(int i = 0;i<n;i++){
if(result<n-i&&slove(i,m)>result){
result = slove(i,m);
}
}
cout<<result;
return 0;
}
