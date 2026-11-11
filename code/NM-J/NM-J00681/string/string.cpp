#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sm,sh;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l]>=a[r]){
			if(c[l]==c[r]){a[l]-=a[r];r--;}
			else {sh+=a[r];a[l]-=a[r];r--;}
		}
		if(a[l]<a[r]){
			if(c[l]==c[r]){a[r]-=a[l];l++;}
			else {sh+=a[l];a[r]-=a[l];l++;}
		}
	}
	cout<<sh;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
