#include<bits/stdc++.h>
using namespace std;
const int R = 200010;
int a[R];
long long LT;
char c[R];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n,k = n/2;
    LT=0;
    while(i<j){
        if(a[i] < a[j]){
            if(c[i] != c[j]){
                LT+=a[i];
            }
            a[j]-=a[i];
            i++;
        }else if(a[i] > a[j]){
            if(c[i] != c[j]){
                LT+=a[j];
            }
            a[i]-=a[j];
            j--;
        }else{
            if(c[i] != c[j]){
                LT+=a[i];
            }
            i++;
            j--;
        }
    }
    cout<<LT;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*

*/
