#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N],ans=0;
char c[N];
void sol(int &i,int &j){
     if(c[i]!=c[j]){
        if(a[i]>a[j]){
           ans+=a[j];
           a[i]-=a[j];
           j--;
        }else{
              ans+=a[i];
              a[j]-=a[i];
              i++;
              if(a[j]==0)j--;
        }
     }
     else{
          if(a[i]>a[j]){
             a[i]-=a[j];
             j--;
          }else{
                a[j]-=a[i];
                i++;
                if(a[j]==0)j--;
          }
     }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    while(i<=j){
          if(c[i]==c[j]&&a[i]==a[j]){
             i++;
             j--;
          }else{
                sol(i,j);
          }
    }
    cout<<ans<<endl;
    return 0;
}
