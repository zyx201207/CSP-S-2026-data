#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct su{
	int num;
	char word;
};
ll n,a[1000005];
su x,y;
char c[1000005];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]==a[j]){
			if(c[i]==c[j]){
				i++;
				j--;
			}
			else{
				ans+=a[i];
				i++;
				j--;
			}
		}
		else if(a[i]>a[j]){
			if(c[i]==c[j]){
				a[i]-=a[j];
				j--;
			}
			else{
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
		}
		else{
			if(c[i]==c[j]){
				a[j]-=a[i];
				i++;
			}
			else{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}	
		}
	}
	cout<<ans;
	return 0;
}