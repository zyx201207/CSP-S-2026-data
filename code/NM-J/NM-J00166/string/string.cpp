#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    long long ans=0;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> c[i];
    }
    int i=1, j=n;
    long long num=0;
    while(i<=j){
        if(c[i]==c[j]){
            if(a[i]<a[j]){
                a[j]=a[j]-a[i];
                a[i]=0;
                i++;
            }else if(a[i]==a[j]){
                a[i]=0;
                a[j]=0;
                i++;
                j--;
            }else{
                a[i]=a[i]-a[j];
                a[j]=0;
                j--;
            }
        }else{
            if(a[i]<a[j]){
                num+=a[i];
                a[j]=a[j]-a[i];
                a[i]=0;
                i++;
            }else if(a[i]==a[j]){
                num+=a[i];
                a[i]=0;
                a[j]=0;
                i++;
                j--;
            }else{
                num+=a[j];
                a[i]=a[i]-a[j];
                a[j]=0;
                j--;
            }
        }
    }
    cout << num << '\n';
    return 0;
}
