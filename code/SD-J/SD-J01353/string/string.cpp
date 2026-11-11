#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
long long sum=0;
char c[200001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int l=1,r=n;l<=r;){
		if(c[l]==c[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}else{
			if(a[l]==a[r]){
				sum+=a[l];
				l++;
				r--;
			}else if(a[l]>a[r]){
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<sum;
	return 0;
}
