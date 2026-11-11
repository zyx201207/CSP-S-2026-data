#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e8+5;
char a[MAXN];
int b[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int k=0;
	cin>>n;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>b[i];
		cin>>a[k];
		for(int j=k+1;j<k+b[i];j++){
			a[j]=a[k];
		}
		k+=b[i];
	}
	for(int i=0;i<k/2;i++){
		if(a[i]!=a[k-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
//tui xiu le QWQ
