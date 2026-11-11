#include<bits/stdc++.h>
using namespace std;
long long n,m,top=0;
long long a[500005];
long long s[500005];
long long t[300005],p[300005];
int main(){
    freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=1000){
        for(int i=1;i<=n;i++){
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        top=0;
        for(int j=i;j<=n;j++){
            top++;
            s[top]=a[j];
            if(t[a[j]]!=0){
                long long k=top-1;
                top--;
                while(s[k]!=a[j]){
                    t[s[k]]--;
                    top--;
                    k--;
                }
                t[a[j]]--;
            }
            t[a[j]]++;
        }
  //      for(int k=1;k<=top;k++){
      //      cout<<s[k]<<" ";
     //   }
    //    cout<<endl;
        for(int k=1;k<=n;k++){
            if(t[k]!=0){
                p[k]++;
            }
        }

    }
    for(int i=1;i<=m;i++){
        cout<<p[i]<<" ";
    }

    }
    else{
        for(int i=1;i<=m;i++){
            cout<<n<<" ";
        }

    }


    return 0;
}
