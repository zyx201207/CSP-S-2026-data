#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n; 
	scanf("%d",&n);
    vector<long long> a(n); 
	vector<char> c(n);
    for(int i=0;i<n;i++) 
	scanf("%ld %c",&a[i],&c[i]);
    int l=0;
	int r=n-1;
    long long offl=0, offr=0;
    long long ans=0;
    while(l<r){
        long long lenl = a[l]-offl, lenr = a[r]-offr;
        long long k = min(lenl, lenr);
        if(c[l]!=c[r]) ans += k;
        offl += k; offr += k;
        if(offl==a[l]){ l++; offl=0; }
        if(offr==a[r]){ r--; offr=0; }
    }
    printf("%ld\n",ans);
    return 0;
}
