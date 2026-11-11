#include<bits/stdc++.h>
using namespace std;
int a[200010],n,ans=0;;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int a1=1,a2=n;
	while(true){
		if(a1>=a2) break;
		if(b[a1]==b[a2]){
			if(a[a1]>a[a2]){
				a[a1]-=a[a2];
				a[a2]=0;
				a2--;
			}
			else if(a[a1]<a[a2]){
				a[a2]-=a[a1];
				a[a1]=0;
				a1++;
			}
			else{
				a[a1]=0;
				a[a2]=0;
				a1++;
				a2--;
			}
		}
		if(b[a1]!=b[a2]){
			if(a[a1]>a[a2]){
				ans+=a[a2];
				a[a1]-=a[a2];
				a[a2]=0;
				a2--;
			}
			else if(a[a1]<a[a2]){
				ans+=a[a1];
				a[a2]-=a[a1];
				a[a1]=0;
				a1++;
			}
			else{
				ans+=a[a1];
				a[a1]=0;
				a[a2]=0;
				a1++;
				a2--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
