#include <bits/stdc++.h>
using namespace std;
long long n,k,a[200005],num;
string s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	long long l=1,r=n,ans=0;
	while(l<r){
        if(c[l]==c[r]){
            if(a[l]<a[r]){
                l++;
                a[r]-=a[l];
            }
            else if(a[l]>a[r]){
                r--;
                a[l]-=a[r];
            }
            else if(a[l]==a[r]){
                l++,r--;
            }
        }
        else {
            if(a[l]<a[r]){
                l++;
                a[r]-=a[l];
                ans+=a[l];
            }
            else if(a[l]>a[r]){
                r--;
                a[l]-=a[r];
                ans+=a[r];
            }
            else if(a[l]==a[r]){
                l++,r--;
                ans+=a[l];
            }
        }
	}
	cout<<ans;
	return 0;
}
