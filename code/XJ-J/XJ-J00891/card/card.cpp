#include <bits/stdc++.h>
using namespace std;
int n,m,f;
int a[200005],s[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++){
		if(s[i]==s[1]){
			f++;
		}else{
			break;
		}
	}
	if(m==2){
		if(s[1]==a[n]){
			cout<<n+1<<" "<<n-f+1;
		}
		return 0;
	}
	
	return 0;
}