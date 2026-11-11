#include <bits/stdc++.h>    
using namespace std;
int n,l,r,k,x;
char s[200000+10];
int a[200000+10];
unsigned long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	l=1;
	r=n;
	while(l<=r){
		if(s[l]!=s[r]){
			ans+=min(a[l],a[r]);
			//k++;
			//cout<<min(a[l],a[r])<<endl;
			//cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<endl;
		}
		x=min(a[l],a[r]);
		a[l]-=x;
		a[r]-=x;
        if(a[l]<=0){
            l++;
        }else{
            r--;
        }
	}
	//cout<<k<<endl;
	cout<<ans;
	return 0;
}
