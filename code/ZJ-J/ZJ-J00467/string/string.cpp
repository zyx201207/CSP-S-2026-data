#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[200005];
char b[200005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","W",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	int j=n;
	int i=1;
	while(j>i){
		if(b[i]==b[j]){
			if(a[i]==a[j]){
				i++;
				j--;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				a[i]-=a[j];
				j--;
			}
		}
		else{
			if(a[i]==a[j]){
				j--;
				ans+=a[i];
				i++;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}else{
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}