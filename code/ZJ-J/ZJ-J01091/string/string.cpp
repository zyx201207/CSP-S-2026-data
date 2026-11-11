#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n;
char c[N];
int a[N];
ll sum=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;){
		if(a[i]>=a[j]){
			a[i]-=a[j];
			if(c[i]!=c[j]) sum+=a[j];
			j--;
		}
		else{
			a[j]-=a[i];
			if(c[i]!=c[j]) sum+=a[i];
			i++;
		}
	}
	cout<<sum;
	return 0;
}//aabbc
