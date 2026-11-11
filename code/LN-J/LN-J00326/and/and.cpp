#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int minn=3*N;
string x,y;
long long ans,sum,summ;
long long a[2*N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    /*
    for(int i=n;i>=n-m+2;i--){
        if(a[i]>=a[i-1])ans=a[i-1];

            /*
        x="";
        y="";
        if(i==n)sum=a[i];
        else sum=ans;
        while(sum){
            x+=(sum%2+'0');
            sum/=2;
        }
        if(i==n)summ=a[i-1];
        else summ=a[i-1];
        while(summ){
            y+=(summ%2+'0');
            summ/=2;
        }
        for(int j=0;j<min(x.size(),y.size());j++){
            if(x[j]==y[j]){
                ans+=pow(2,j);
            }
        }
    }
    */
    cout<<a[n-m+1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
