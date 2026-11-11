#include <bits/stdc++.h>

using namespace std;

long long a[200010];
char c[200010];
char vec[1000000010];
long long n;
long long cnt=0;
long long k=-1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.ans","w",stdout);

    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(long long j=1;j<=a[i];j++){
            vec[++k] = c[i];
        }
    }
    if((k+1)%2==1){
        for(long long i=0;i<(k+2)/2;i++){
            if(vec[i]!=vec[k-i])
                cnt++;
        }
    }else{
        for(long long i=0;i<(k+1)/2;i++){
            if(vec[i]!=vec[k-i])
                cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
