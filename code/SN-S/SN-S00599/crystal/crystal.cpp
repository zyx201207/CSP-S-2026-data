#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=0,j=0;
	long long a[100005],c[100005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(i!=0){
			c[i]=a[i]-a[i-1];
		}
	}	

	for(int i=0;i<n;i++){
		m-=c[j]*i;
	    if(m>=0){
	    	j++;
		    cnt++;

		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);

	return 0; 
}
