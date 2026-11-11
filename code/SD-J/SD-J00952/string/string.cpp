#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5; 
int n,ans;
int a[N];
char c[N];
string S;
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)
			S+=c[i];
	int L=S.size();
	int l=0,r=L-1;
	while(l<r){
		if(S[l]!=S[r]){
			S[l]=S[r];
			ans++;
			l++;r--;
		}
		else{
			l++;r--;
		}
	}
	cout<<ans;
	return 0;
}


