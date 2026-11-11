#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n;
struct str{
	int n;char c;
}a[maxn],b[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].n>>a[i].c;
	}
	for(int i=0;i<n;i++){
		b[i].n=a[n-i-1].n;
		b[i].c=a[n-i-1].c;
	}
	int i=0,j=0;
	long long ans=0; 
	while(i!=n||j!=n){
		int k=min(a[i].n,b[j].n);
		a[i].n-=k;b[j].n-=k;
		if(a[i].c!=b[j].c){
			ans+=k;
		}if(a[i].n==0){
			i++;
		}if(b[j].n==0){
			j++;
		}
	}
	ans/=2;
	cout<<ans<<endl;
}