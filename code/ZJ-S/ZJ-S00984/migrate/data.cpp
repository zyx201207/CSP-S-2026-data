#include <bits/stdc++.h>
using namespace std;
mt19937 rnd((random_device())());

int main() {
    freopen("data.in","w",stdout);
    int T=rnd()%1000+1;
    printf("0 %d\n",T);
    while(T--) {
        int n=rnd()%100+1,V=rnd()%100+1;
        vector<int> arr;
        for(int i=1;i<=n;i++) arr.push_back(rnd()%(2*V+1)-V);
        sort(arr.begin(),arr.end());
        printf("%d %d\n",n,rnd()%V+1);
        for(int i=0;i<n;i++) printf("%d ",arr[i]+i);printf("\n");
    }
    return 0;
}
