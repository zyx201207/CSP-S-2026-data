#include<bits/stdc++.h>
using namespace std;
int a[200010];
char b[200010];
unsigned long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]!=a[j]){
			if(a[i]<a[j]){
				if(b[i]!=b[j]){
					cnt+=a[i];
				}
				a[j]-=a[i];
				i++;
			}else{
				if(b[i]!=b[j]){
					cnt+=a[j];
				}
				a[i]-=a[j];
				j--;
			}
		}else{
			if(b[i]!=b[j]){
				cnt+=a[i];
			}
			i++;
			j--;
		}
	}
	cout<<cnt;
	return 0;
}
