#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;
using ll=long long;
int n,m;
int a[500010];
int T;
ll o=0;
//const ll N=125000250000;
//greater<>;
//vector<>a;
//stack<>;
//queue q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//cin>>T;
	//while(T--){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int sum=1;
    //for(int i=1;i<=m;i++){
     //   a[sum]+=1;
      //  if(a[sum]==a[sum+1]){
       //     sum=1;
       // }
    //}
    o=a[2]-a[1];
 //   if(m>N){
  //      cout<<n;
  //      return 0;
  //  }
    int ans1=0,ans2=1;

    for(int i=1;i<=m;i+=o){
        a[sum]+=o;
        if(a[sum]<a[sum+1]){
            ans1=sum;sum=1;
        }else if(a[sum]==a[sum+1]){
            int ans;
           for(int j=sum;j<=n;j++){
                if(a[j]==a[sum])ans++;
                else break;
            }
            ans1=sum+1;sum=1;
        }else sum++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1])ans2++;
    }
    cout<<max(ans2,ans1);
    //cout<<min((int)sqrt(m*2),n);
	//}
return 0;
}
