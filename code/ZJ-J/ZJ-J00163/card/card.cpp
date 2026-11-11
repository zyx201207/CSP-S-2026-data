#include <iostream>
using namespace std;

int N,M;
int A[500005];

int pos[300005];
int ans[300005];

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin >> N>>M;
    for (int i=1;i<=N;i++) {
        cin >> A[i];
        pos[A[i]]=i;
    }

    for (int i=1;i<=N;i++) {
        int j=i;
        while (j<=N) {
            j=pos[A[j]];
            ans[A[j]]++;
            j++;
        }
    }

    for (int i=1;i<=M;i++) {
        cout << ans[i]<<" ";
    }


    return 0;
}