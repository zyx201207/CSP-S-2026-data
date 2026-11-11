#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[200001],b[200001],sum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=i;j<n;j++){
            b[i]=a[i];
            if(b[j]==a[i]){
                b[j]=a[i];
                for(int s=j+1;s<=i;s++){
                    b[s]=0;
                }
            }
            for(int f=1;f<=m;f++){
            for(int x=1;x<=n;x++){
                if(b[i]==f) sum++;
            }
            cout<<sum<<" ";
            sum=0;
        }
        return 0;
        }

    }
}
