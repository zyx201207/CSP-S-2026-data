#include <bits/stdc++.h>
using namespace std;
long long n,m,sum;
bool flag=true;
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    vector<long long> a(n+1);
    cin >> a[0];
    sum=a[0];
    for(int i=1;i<n;i++) {
        cin >> a[i];
        if(a[i]!=i-1) flag=false;
        sum&=a[i];
    }
    if(flag) {
        cout << n-m;
    } else if(m==1) {
        cout << a[n-1];
    } else if(m==n) {
        cout << sum;
    } else if(m==2) {
        sum=-1;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                sum=max(sum,(long long)(a[i]&a[j]));
            }
        }
        cout << sum << '\n';
	} else if(m==n-1) {
        long long sum2=-1;
        for(int i=0;i<n;i++) {
            sum2=max(sum2,(long long)(~(sum^a[i])));
        }
        cout << sum2 << '\n';
	} else {
        sort(a.begin(),a.end());
        cout << a[n-m+1] << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
