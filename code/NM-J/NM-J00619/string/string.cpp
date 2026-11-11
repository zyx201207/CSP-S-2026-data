#include<bits/stdc++.h> 
using namespace std;
int n,a[200005],e,s=0,m;
char b[200005];
long long cnt,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	e=n-1;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	while(e>s){
		m=min(a[s],a[e]);
		if(b[s]!=b[e]){
			cnt+=m;
		}
		if(a[s]<a[e]){
			a[e]-=a[s];
			a[s]=0;
			s++;
		}
		else if(a[s]>a[e]){
			a[s]-=a[e];
			a[e]=0;
			e--;
		}
		else{
			a[s]=0;
			a[e]=0;
			s++;
			e--;
		}
	}
	cout<<cnt; 
	return 0;
}
