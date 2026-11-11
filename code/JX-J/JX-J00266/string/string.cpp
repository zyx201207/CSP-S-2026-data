#include<iostream>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        getchar();
        scanf("%c",&c[i]);
    }
    long long ans=0;
    int i=1,j=n;
    while (i<j){
        int sum=min(a[i],a[j]);
        if (c[i]!=c[j]) ans+=sum;
        a[i]-=sum,a[j]-=sum;
        if (!a[i]) i++;
        if (!a[j]) j--;
    }
    cout<<ans;
    return 0;
}
