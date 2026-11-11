#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100010];
long long m;
long long ans;
bool cc;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        while(m>0&&a[i]!=a[i+1]){
            if(m>=i){


            a[i]++;
            m--;
            if(i!=1){

                for(int j=i-1;j>0;j--){
                    a[j]++;
                    m--;

                }
            }


        }
        else{
            cout<<i;

            return 0;
        }

        }
    }
//    for(int i=1;i<=n;i++){
//        cout<<a[i];
//    }
    for(int i=1;i<=n;i++){
            //cout<<a[i];
        if(a[i]==a[i+1]){
            ans++;
        }
    }

    //cout<<m;
    cout<<ans+1;
    return 0;
}
