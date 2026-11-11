#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],ans=INT_MIN,andd,p,q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int p=1;p<m;p++){
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				andd=a[i]&a[j];
				ans=max(ans,andd);
				p=i,q=j;
			}
		}
		a[p]=ans,a[q]=0,ans=INT_MIN;
	}
	cout<<andd;
	return 0;
}
