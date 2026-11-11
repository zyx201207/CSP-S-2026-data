#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+100;
typedef unsigned long long ll;

int n;
ll a[MAXN],ans=0;
char c[MAXN];


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int i=1,j=n;
	while(i<=n&&j>=1&&i>=1&&j<=n&&i<j){
		if(c[i]!=c[j]){
			int mn=min(a[i],a[j]);
			int mx=max(a[i],a[j]);
			ans+=mn;
			if(a[i]>a[j]){
				a[i]-=mn;
				j--;
			}
			else if(a[i]==a[j]){
				i++;j--;
			}
			else{
				a[j]-=mn;
				i++;
			}
		}
		else{
			int mn=min(a[i],a[j]);
			int mx=max(a[i],a[j]);
			if(a[i]>a[j]){
				a[i]-=mn;
				j--;
			}
			else if(a[i]==a[j]){
				i++;j--;
			}
			else{
				a[j]-=mn;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
