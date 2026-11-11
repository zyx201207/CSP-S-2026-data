#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
long long cnt=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long i=1,j=n;
	while(i<j){
		if(a[i]==a[j]&&c[i]==c[j]){
			i++;
			j--;
			continue;
		}
		if(a[i]==a[j]&&c[i]!=c[j]){
			cnt+=a[i];
			i++;
			j--;
			continue;
		}
		if(a[i]<a[j]){
			if(c[i]==c[j]){
				a[j]-=a[i];
				i++;
			}
			else{
				a[j]-=a[i];
				cnt+=a[i];
				i++;
			}
		}
		else{
			if(c[i]==c[j]){
				a[i]-=a[j];
				j--;
			}
			else{
				a[i]-=a[j];
				cnt+=a[j];
				j--;
			}	
		}	
	}
	cout<<cnt;
	return 0;
} 
