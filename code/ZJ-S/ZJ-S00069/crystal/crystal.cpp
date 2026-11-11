#include <bits/stdc++.h>
using namespace std;
int n,pos=1,mi=1,sum=1;long long m;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            sum+=1;
        }else{
            if(sum>mi){
                mi=sum;
                pos=i-sum;
                sum=1;
            }
        }
    }
    if(sum>mi){
            mi=sum;
            sum=1;
            pos=n-sum;
        }
    int state=a[pos],or_pos=pos+mi;
    pos--;
    //cout<<mi<<' '<<pos<<' '<<or_pos<<'\n';
    while(m>0&&pos>=1){
        if(m>=state-a[pos]){
            m=m-(state-a[pos]);
            mi++;
            pos--;
        }
        else{
            break;
        }
    }
    pos=1;
    //cout<<mi<<' '<<pos<<' '<<or_pos<<'\n';
    while(m>0){
        if(m>=(a[or_pos]-a[pos])*(or_pos-1)){
            m-=(a[or_pos]-a[pos])*(or_pos-1);
            a[pos]=a[or_pos];
            mi++;
            //cout<<mi;
            or_pos++;
        }
        else{
            break;
        }
    }
    cout<<mi;
    return 0;
}