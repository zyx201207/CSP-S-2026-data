#include <bits/stdc++.h>
using namespace std;
long long n,a[200001];
unsigned long long ans=0;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long a1=1,a2=n;
	while(a1<a2){
		if(c[a1]!=c[a2]){
			ans+=min(a[a1],a[a2]);
			if(a[a1]>a[a2]){
				a[a1]=a[a1]-a[a2];
				a2-=1;	
			}
			else if(a2>a1){
				a[a2]=a[a2]-a[a1];
				a1+=1;
			}
			else{
				a1+=1;
				a2-=1;
			}
		}
		else{
			if(a[a1]>a[a2]){
				a[a1]=a[a1]-a[a2];
				a2-=1;
			}
			else if(a2>a1){
				a[a2]=a[a2]-a[a1];
				a1+=1;
			}
			else{
				a1+=1;
				a2-=1;
			}
		}
	}
	cout<<ans;
	return 0;
}//Trick||Treat!
