#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200001],as;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++)
        cin >>a[i]>>c[i];
    int l=1,r=n;
    while(l<=r){
        if(a[l]>a[r]){
            if(c[l]!=c[r])
                as+=a[r];
            a[l]-=a[r];
            r--;
        }
        if(a[r]>a[l]){
            if(c[l]!=c[r])
                as+=a[l];
            a[r]-=a[l];
            l++;
        }
        if(a[l]==a[r]){
            if(c[l]!=c[r])
                as+=a[l];
            l++,r--;
        }
    }
    cout <<as;
	return 0;
}
