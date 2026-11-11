#include<bits/stdc++.h>
using namespace std;
long long a[200010];char c[200010];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,ans=0;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >> a[i]>>c[i];
		sum+=a[i];
	}
	long long l1=1,r1=n;
	while(l1<=r1){
		if(c[l1]==c[r1]){
			if(a[l1]>a[r1]){
				a[l1]-=a[r1];				
				r1--;
			}else if(a[l1]<a[r1]){
				a[r1]-=a[l1];			
				l1++;
			}else{
				l1++;
				r1--;
			}
		}else{
			if(a[l1]>a[r1]){
				ans+=a[r1];
				a[l1]-=a[r1];
				r1--;
			}else if(a[l1]<a[r1]){
				ans+=a[l1];
				a[r1]-=a[l1];
				l1++;
			}else{
				ans+=a[l1];
				r1--;
				l1++;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}