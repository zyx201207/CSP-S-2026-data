#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;;){
		for(int j=n;j>i;){
			if(c[i]==c[j]){
				if(a[i]<a[j]){
					a[j]-=a[i];
					i++;
				}
				else if(a[j]<a[i]){
					a[i]-=a[j];
					j--;
				}
				else if(a[i]==a[j]){
					i++,j--;
				}
			}
			else if(c[i]!=c[j]){
				if(a[i]<a[j]){
					a[j]-=a[i];
					ans+=a[i];
					i++;
				}
				else if(a[j]<a[i]){
					a[i]-=a[j];
					ans+=a[j];
					j--;
				}
				else if(a[j]==a[i]){
					ans+=a[i];
					i++,j--;
				}
			}
		}
		break;
	}
	cout<<ans;
	return 0;
}
