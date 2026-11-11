//love lyt
#include <bits/stdc++.h>
using namespace std;
long long m,n,sum=1;
bool s=true;
long long a[500005],l[500005],sum1[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(i>=2){
            l[i] = a[i]-a[i-1];
        }
        if(i >=3 && a[i]-a[i-1] != a[i-1]-a[i-2]){
            s = false;
        }
    }
    
    if(s == true){
        int x = m;
        for(int i=1;i<=n;i++){
            if(x-i*(a[2]-a[1])>0){
                sum++;
                x=x-i*(a[2]-a[1]);
            }else{
                break;
            }
        }
        
    }else{
        int x = m;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(x-j*(l[j])>0){
                    sum1[i]++;
                    x=x-i*(l[j]);
                }
            }
            if(sum1[i] > sum){
                sum = sum1[i]+1;
            }
        }

    }
    cout << sum << endl;
    return 0;
}