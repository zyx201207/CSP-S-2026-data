#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n,a[201000];
	long long int ma=0;
	char s[201000];
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&s[i]);
	}
	int l=1,r=n;
	while(l<r){
		int q=1;
		if(s[l]==s[r]){
			q=0;
		}
		if(a[l]<a[r]){
			ma+=a[l]*q;
			a[r]-=a[l];
			l++;
		}
		if(a[l]>a[r]){
			ma+=a[r]*q;
			a[l]-=a[r];
			r--;
		}else {
			ma+=a[l]*q;
			l++;
			r--;
		}
	}
	cout<<ma;
	return 0;
}