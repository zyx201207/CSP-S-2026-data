#include<iostream>
using namespace std;

string c1,s1,c2,s2;
int n,a[300005];
char b[300005];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>b[i];
	}
	int j=n,i=1;
	while(i<j){
		if(a[i]==a[j]&&b[i]==b[j]){
			i++,j--;
			continue;
		}
		if(a[i]!=a[j]&&b[i]==b[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}
			continue;
		}
		if(a[i]==a[j]&&b[i]!=b[j]){
			ans=ans+a[j];
			i++,j--;
			continue;
		}
		if(a[i]!=a[j]&&b[i]!=b[j]){
			if(a[i]>a[j]){
				ans=ans+a[j];
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
		    	ans=ans+a[i];
				a[j]-=a[i];
				i++;
			}
			continue;
		}
	}
	cout<<ans;
	return 0;
}
