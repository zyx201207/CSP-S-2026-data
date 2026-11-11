#include<iostream>
using namespace std;
int n;
long long a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;){
		if(c[i]==c[j]){
			if(a[i]>a[j])a[i]-=a[j--];
			else if(a[i]<a[j])a[j]-=a[i++];
			else i++,j--;
		}else{
			if(a[i]>a[j])a[i]-=a[j],ans+=a[j--];
			else if(a[i]<a[j])a[j]-=a[i],ans+=a[i++];
			else j--,ans+=a[i++];
		}
	}
	cout<<ans;
	return 0;
}
