#include <iostream>
using namespace std;

int N;
int A[200005];
char C[200005];

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> N;
    
    for (int i=0;i<N;i++) {
        cin >> A[i]>> C[i];
    }
    
    int i=0,j=N-1;
    int l=A[i], r=A[j];
    long long ans=0;
    
    while (i<j) {
        if (l>r) {
            if (C[i]!=C[j]) {
                ans+=r;
            }
            l-=r;
            j--;
            r=A[j];
        }
        if (l<r) {
            if (C[i]!=C[j]) {
                ans+=l;
            }
            r-=l;
            i++;
            l=A[i];
        }
        if (l==r) {
            if (C[i]!=C[j]) {
                ans+=l;
            }
            i++;j--;
            l=A[i];r=A[j];
        }
    }

    cout << ans;

    

    return 0;
}