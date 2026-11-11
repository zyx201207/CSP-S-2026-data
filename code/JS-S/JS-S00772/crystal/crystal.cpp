//Shhh, I see dead people
#include<bits/stdc++.h>
using namespace std;
int n;
long long tmp1,tmp2,t;
long long mid,midd;
long long sum=0,cnt=0;
long long m;
long long a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    // Mustard on the beat ho~
    sort(a+1,a+n+1);
    mid=n/2+1;
    midd=a[mid];
    for(int i=mid,j=mid+1;i>=1,j<=n;i--,j++){
        tmp1=midd-a[i];
        tmp2=a[j]-midd;
        if(tmp1<tmp2){
            sum+=tmp1;
            j--;
            cnt++;
        }else if(tmp1>tmp2){
            sum+=tmp2;
            i++;
            cnt++;
        }else{
            t=tmp1+tmp2;
            if(t+sum<=m){
                sum+=t;
                cnt+=2;
            }else{
                if(midd-a[i-1]<a[j+1]-midd){
                    sum+=tmp1;
                    j--;
                    cnt++;
                }else if(midd-a[i-1]>a[j+1]-midd){
                    sum+=tmp2;
                    i++;
                    cnt++;
                }
            }
        }
    }
    //Mustard on the beat ho~
    cout<<cnt<<"\n";
}
