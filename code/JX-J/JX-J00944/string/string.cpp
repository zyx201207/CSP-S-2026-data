#include <bits/stdc++.h>
using namespace std;
long long n;
string c;
long long sumz,sumf,cntz,cntf,num;
int a[10010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i] >> c[i];
    }
    int i = 0;
    n-=1;
    cntf = n;
    while(cntz <= cntf){
        sumz +=a[cntz];
        cntz++;
        sumf+=a[cntf];
        cntf--;
        if(sumz > sumf){
            if(c[cntz]!=c[cntf]){
                num+=sumf;
            }
            sumz -=sumf;
            sumf = 0;
        }else if(sumf > sumz){
            if(c[cntz]!=c[cntf]){
                num += sumz;
            }
            sumf -= sumz;
            sumz = 0;
        }else{//sumf == sumz
            if(c[cntz]!=c[cntf]){
                num += sumz;

            }
            sumf -= sumz;
            sumz = 0;
        }
    }
    cout << num;

    return 0;
}
