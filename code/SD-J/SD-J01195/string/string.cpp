#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n,h;
	while(i<j){
		h=min(a[i],a[j]);
		if(c[i]==c[j]){
			a[i]-=h;
			a[j]-=h;
		}else{
			ans+=h;
			a[i]-=h;
			a[j]-=h;
		}
		if(!a[i]){
			i++;
		}
		if(!a[j]){
			j--;
		}
	}
	cout<<ans;
	return 0;
}
