#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],da[300005],zm[500005],kf[300005],i,j;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(i=n-1;i>=0;i--)
        cin>>a[i];
    for(i=1;i<=m;i++)
        kf[i]=-1;
    for(i=0;i<n;i++)
        zm[i]=-1;
    for(i=0;i<n;i++){
        if(kf[a[i]]>-1){
            j=i-1;
            zm[i]=kf[a[i]];
            kf[a[zm[i]]]=-1;
            while(j>zm[i]){
                if(zm[j]>-1)
                    j=zm[j];
                j--;
                kf[a[j]]=-1;
            }
        }
        else
            kf[a[i]]=i;
        j=i;
        while(j>=0){
            if(zm[j]>-1)
                j=zm[j]-1;
            else{
                da[a[j]]++;
                cout<<a[j]<<" ";
                j--;
            }
        }
        cout<<endl;
    }
    for(i=1;i<=m;i++)
        cout<<da[i]<<" ";
    return 0;
}
