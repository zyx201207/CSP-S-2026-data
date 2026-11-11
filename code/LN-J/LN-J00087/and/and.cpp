#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2*1e5+5;
int a[N];
int maxx=-1;
int ans;
long long cap[35];
int miao(int x,int y){
int i=1,j=1;
int ans=0;
while(x<cap[i])i++;
while(y<cap[j])j++;
i--;
j--;
i=min(i,j);
while(x>cap[i]) x-=cap[i];
while(y>cap[i])y-=cap[i];
for(i;i>0;i--){
    if(x>=cap[i]){
        x-=cap[i];
        if(y>=cap[i]){
            y-=cap[i];
            ans+=cap[i];
        }
    }
    else{
        if(y>=cap[i]){
          while(y>cap[i])  y-=cap[i];
        }
    }
}
return ans;
}




int dfs(int x,int i){
if(x>m)return 0;
if(i>n)return 0;

int b=miao(a[i],dfs(x+1,i+1));
int c=dfs(x,i+1);
return max(b,c);

}

int main(){

     freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cap[1]=1;
    for(int i=1;i<=30;i++){
    cap[i]=cap[i-1]*2;
    }
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
cout<<dfs(0,1);
}
