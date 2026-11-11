#include<iostream>
#include<cstring>
#define int long long
using namespace std;
int a[200005];
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}int i=0,j=n-1,ans=0;
	while(i<=j){
		if(b[i]==b[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]==a[j]){
				i++,j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}else{
			ans+=min(a[i],a[j]);
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]==a[j]){
				i++,j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}
	}cout<<ans;
	return 0;
}
