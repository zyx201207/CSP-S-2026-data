#include<bits/stdc++.h>
using namespace std;
string a="0";
int n;
int q;
string d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q>>d;
		for(int j=1;j<=q;j++){
			a+=d;
		}
	}
	int ans=0;
	for(int i=1,j=a.size()-1;i<=a.size()/2;i++,j--){
		if(a[i]!=a[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
