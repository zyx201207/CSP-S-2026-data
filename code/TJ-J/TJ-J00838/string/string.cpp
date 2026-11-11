#include<bits/stdc++.h>
using namespace std;
string S;
int n,a[200005],s[100005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
//		s[i]=a[i];
//		for(int j=1;j<=i;j++){
//			S[j]=S[j]+c[j];
//			cout<<S[j];
//		}
		
	}
	
	for(int i=1;i<=n;i++){
		if(c[i]==c[i+1]){
			cout<<0;
		}
	}
	return 0;
}
