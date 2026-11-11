#include<bits/stdc++.h>
using namespace std;
map<long long,int> mp[30],mp1[30];
long long a[200010];
char b[200010];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long cnt=0,j=n;
	for(int i=1;i<=n;i++){
		if(i==j)break;
		if(a[i]==a[j]){
			if(b[i]!=b[j]){
				cnt+=a[i];
			}
			j--;
		}
		else if(a[i]<a[j]){
			if(b[i]!=b[j]){
				cnt+=a[i];
			}
			a[j]-=a[i];
		}
		else{
			if(b[i]!=b[j]){
				cnt+=a[j];
			}
			a[i]-=a[j];
			i--;
				j--;
		}
	}
	cout<<cnt;
	return 0;
}
                              