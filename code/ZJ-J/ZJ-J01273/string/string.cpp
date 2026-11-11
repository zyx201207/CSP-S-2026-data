#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,ans;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int i=1,j=n;
	while(sum&&i!=j){
		if(c[i]!=c[j]){
		    if(a[i]>a[j]){
		    	ans+=a[j];
		    	sum-=a[j];
		    	a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				ans+=a[i];
				sum-=a[i];
				a[j]-=a[i];
				i++;
			}else{
				ans+=a[j];
				sum-=(a[j]+a[i]);
				j--;i++;
			}
	    }else{
	    	if(a[i]>a[j]){
	    		sum-=a[j];
		        j--;
			}else if(a[i]<a[j]){
				sum-=a[i];
				i++;
			}else{
				sum-=(a[j]+a[i]);
				j--;i++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	return 0;
}
