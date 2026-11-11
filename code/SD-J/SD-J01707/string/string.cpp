#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long ans,a[200005],n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int i=1,j=n;
	while(i<j){
		if(c[i]!=c[j]){
			if(a[i]<=a[j]){
				ans=ans+a[i];
				a[j]=a[j]-a[i];
				i++;
			}else{
				ans=ans+a[j];
				a[i]=a[i]-a[j];
				j--;
			}
		}else{
			if(a[i]<=a[j]){
				a[j]=a[j]-a[i];
				i++;
			}else{
				a[i]=a[i]-a[j];
				j--;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
