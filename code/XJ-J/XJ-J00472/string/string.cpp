#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	long long int sum;
	char c;
}a[N];
long long int n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].c;
	}
	long long int i=1,j=n;
	while(i<=j){
		if(a[i].sum>a[j].sum){
			if(a[i].c!=a[j].c){
				ans+=a[j].sum;	
			}
			a[i].sum-=a[j].sum;
			j--;
		}
		else if(a[i].sum==a[j].sum){
			if(a[i].c!=a[j].c){
				ans+=a[j].sum;
			}
			i++,j--;
		}
		else if(a[i].sum<a[j].sum){
			if(a[i].c!=a[j].c){
				ans+=a[i].sum;
				
			}
			a[j].sum-=a[i].sum;
			i++;
		}
	}
	cout<<ans;
	return 0;
}
