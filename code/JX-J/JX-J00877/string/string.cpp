#include <bits/stdc++.h>
using namespace std;
struct cs{
    int a1;
    char a2;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cs a[200005];
    long long n,sum=0,l1=-1,l2=-1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].a1>>a[i].a2;
    }
    l1=a[0].a1;
    l2=a[n-1].a1;
    for(int i=0,j=n-1;i!=j;i=i){
        if(a[i].a2==a[j].a2){
            if(l1>l2){
                l1=l1-l2;
                j--;
                l2=a[j].a1;
            }else if(l1==l2){
                i--;
                j--;
                l1=a[i].a1;
                l2=a[j].a1;
            }else{
                l2=l2-l1;
                i++;
                l1=a[i].a1;
            }
        }else{
            if(l1>l2){
                sum+=l2;
                l1=l1-l2;
                j--;
                l2=a[j].a1;
            }else if(l1==l2){
                sum+=l2;
                i--;
                j--;
                l1=a[i].a1;
                l2=a[j].a1;
            }else{
                sum+=l1;
                l2=l2-l1;
                i++;
                l1=a[i].a1;
            }
        }

    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
