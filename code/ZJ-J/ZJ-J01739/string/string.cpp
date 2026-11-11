#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m[200005],ans=0;
char a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long j=0;
	for(int i=0;i<n;i++){
		cin>>m[i]>>a[i];
		j+=m[i];
	}
	int i=0,q=n-1;
	while(i<q){
		if(a[i]!=a[q]){
			ans+=min(m[i],m[q]);
		}
		if(m[i]>m[q]){
			m[i]-=m[q];
			q--;
		}
		else if(m[i]<m[q]){
			m[q]-=m[i];
			i++;
		}
		else{
			i++;
			q--;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
