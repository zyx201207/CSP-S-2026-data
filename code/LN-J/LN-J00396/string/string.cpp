#include<bits/stdc++.h>
using namespace std;
int p[11451419];
char c[11451419];
long long sum=0,mid=0,cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string a;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>c[i];
        sum+=p[i];
        for(int j=1;j<=p[i];j++){
            a+=c[i];
        }
    }
    //cout<<a<<' ';
    if(sum%2==1){
        mid=sum/2+1;
    }
    else{
        mid=sum/2;
    }
    //cout<<mid<<"\n";
    if(sum%2==0){
        for(int i=0,j=a.size()-1;i<mid,j>=mid;i++,j--){
        if(a[i]!=a[j]){
            //cout<<i<<' '<<j<<' '<<a[i]<<' '<<a[j]<<" ";
            //cout<<cnt<<"\n";
            cnt++;
        }
        }
        cout<<cnt;
    }
    else{
        for(int i=0,j=a.size()-1;i<mid,j>mid;i++,j--){
        if(a[i]!=a[j]){
            //cout<<i<<' '<<j<<' '<<a[i]<<' '<<a[j]<<" ";
            //cout<<cnt<<"\n";
            cnt++;
        }
        }
        cout<<cnt;
    }

    return 0;
}
