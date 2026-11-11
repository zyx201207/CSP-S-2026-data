#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,s=0;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]==a[r]){
				l++;
				r--;
			}else{
				a[l]-=a[r];
				r--;
			}
		}else{
			if(a[l]<a[r]){
				s+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[l]==a[r]){
				s+=a[l];
				l++;
				r--;
			}else{
				s+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}