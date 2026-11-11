#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
long long sum=0;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        long long s=0;
        long long h=m;
        for(int j=i;j>=0;j--){
            if(a[j]==a[i]){
                s++;
            }
            else if(a[j]<a[i]&&h-abs(a[j]-a[i])>=0){
                s++;
                h-=abs(a[j]-a[i]);
            }else{
            	break;
			}
        }
        sum=max(sum,s);
    }
    cout<<sum;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

