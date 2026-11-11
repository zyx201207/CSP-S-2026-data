#include<bits/stdc++.h>
using namespace std;
long long int a[2000005][2];
long long int sum,n;
char x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int j=1;j<=n;j++)
    {
        cin>>a[j][0];
        cin>>x;
        a[j][1]=x;
        //cout<<a[j][1]<<endl; ok
    }
    long long int i=1,g=n-i+1,maxx,minn,p=i-g;
    while(i!=g)
    {
        minn=min(a[i][0],a[g][0]);
        if(a[i][1]!=a[g][1])
            sum+=minn;
        //cout<<sum<<' '<<i<<g<<endl;
        a[i][0]-=minn;
        a[g][0]-=minn;
        if(a[i][0]<a[g][0])
        {
            i++;
            n+=1;
        }
        else if(a[i][0]>a[g][0])
        {
            n-=1;
        }
        else
        {
            i++;
        }
        g=n-i+1;
        p=i-g;
        if(p==1)
            break;
    }
    cout<<sum;
}
