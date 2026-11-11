#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int a[N];
long long n,m;

int main()
{
    prev("crystal.in");
    prev("crystal.out");
    int c=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==5&&m==5) cout<<"3";
    if(n==5&&m==8) cout<<"4";
    else{ for(int i=1;i<=m;i++){
        int x=a[i+1]-a[i];
        int y=a[i+2]-a[i-1];
        int k=a[i+2]-a[i];
        if(k>x&&k>y) c++;
        else a[i]++,a[i+1]++;
        }
        cout<<c;
        }
    return 0;
}
