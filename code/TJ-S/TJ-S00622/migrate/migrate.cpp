#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],l; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;long long q1,q2;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
			
		}l=0;
		for(int j=1;j<=n-3;j++){
			if(a[j+3]-a[j]>d&&a[j+3]-a[j+2]<d&&a[j+2]-a[j+1]<d&&a[j+1]-a[j]<d)l++;
		}
		cout<<l<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
