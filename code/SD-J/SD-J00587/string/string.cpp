#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n;
int a[N];
char c[N];
long long len;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long ans=0;
	int i=1,j=n;
	while(i<j){
		if(c[i]==c[j]){
			if(a[i]==a[j]){
				i++,j--;
			}
			else if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=0;
				j--;
			}
			else{
				a[j]-=a[i];
				a[i]=0;
				i++;
			}
		}
		else{
			if(a[i]==a[j]){
				ans+=a[i];
				i++,j--;
			}
			else if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				a[j]=0;
				j--;
			}
			else{
				ans+=a[i];
				a[j]-=a[i];
				a[i]=0;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
