    #include<bits/stdc++.h>
    using namespace std;
    int n,m,a[500005],sum=0;
    int main(){
      freopen("card.in","r",stdin);
      freopen("card.out","w",stdout);
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sum=n;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]){
                sum--;
            }
        }
        cout<<n<<" "<<sum;
        return 0;
    }
