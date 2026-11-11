#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
long long an;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int j=n-1;
	for(int i=0;i<j;){
		if(c[i]!=c[j]){
			an+=min(a[i],a[j]);
		}
		if(a[i]>a[j]){
			a[i]-=a[j];
			j--;
		}else if(a[i]<a[j]){
			a[j]-=a[i];
			i++;
		}else{
			j--;
			i++;
		}
	}
	cout<<an;
	return 0;
}
/*

*/