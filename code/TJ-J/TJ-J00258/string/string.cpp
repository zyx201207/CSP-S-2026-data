#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,ans2,cnt;
string c[200005],s[200005]; 
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			ans++;
			s[ans]+=c[i];
		}
	}
	ans2=ans;
	for(int i=1;i<=ans/2;i++){
		if(s[i]!=s[ans2]){
			cnt++;
		}
		ans--;
	}
	cout<<cnt;
	return 0;
} 


