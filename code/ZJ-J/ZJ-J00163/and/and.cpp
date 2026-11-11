#include <iostream>
using namespace std;

int N,M;
long long A[200005];

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> N>>M;
    for (int i=0;i<N;i++) {
        cin >> A[i];
    }

    for (long long t=1<<30;t>=1;t>>=1) {
        int sum=0;
        for (int i=0;i<N;i++) {
            if ((A[i]&t)>0) {
                sum++;
            }
        }
        if (sum<M)
            continue;
        
        for (int i=0;i<N;i++) {
            if ((A[i]&t)==0) {
                A[i]=0;
            }
        }
    }
    int sum=0;
    long long ans=0;
    for (int i=0;i<N;i++) {
        if (A[i]!=0) {
            sum++;
            ans = ans==0?A[i]:(ans&A[i]);
        }
        if (sum==M) {
            break;
        }
    }

    if (sum<M) {
        cout << 0;
    }else{
        cout << ans;
    }

    return 0;
}