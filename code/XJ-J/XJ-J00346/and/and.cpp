#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=2e5+5;
int n,m;
int arr[N],amax[N][N-M+1];
int main() {
    ios::sunc_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++) {
        for(int qcnt=1;qcnt+m<n;qcnt++) {
            int sum=arr[i],cnt=m;
            for(int j=qcnt;j<=n;j++) {
                if(i==j) continue;
                if(!(m--)) {
                    break;
                }
                sum&=arr[j];
            }
            amax[i][qcnt]=sum;
        }
    }int max=-2147483647;
    for(int i=1;i<=n;i++) {
        for(int j=1;j+m<n;j++) {
            max=(max<amax[i][j] ? amax[i][j] : max);
        }
    }
    cout<<max;
    return 0;
}