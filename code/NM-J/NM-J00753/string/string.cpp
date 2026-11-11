#include<bits/stdc++.h>
using namespace std;
long long a[300005];
char t[300005];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,n,l,r,s=0;
	cin >> n;
	for(i=1;i<=n;i++){
        cin >> a[i] >> t[i];
	}
	for(l=1,r=n;l<r;){
        if(t[l]!=t[r]){
            if(a[l]>a[r]){
                s+=a[r];
                a[l]-=a[r];
                r--;
            }else if(a[l]==a[r]){
                s+=a[r];
                r--;l++;
            }else{
                s+=a[l];
                a[r]-=a[l];
                l++;
            }
        }else{
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }else if(a[l]==a[r]){
                r--;l++;
            }else{
                a[r]-=a[l];
                l++;
            }
        }
	}
	cout << s;
	return 0;
}

