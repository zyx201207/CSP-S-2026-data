#include<bits/stdc++.h>
using namespace std;
long long m,d,n,ans=0;
char zm;
string b;
bool l=1;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>zm;
		d+=m;
		for(int j=1;j<=m;j++){
			b+=zm;
		}
	}
	for(int i=0,j=b.size()-1;i<=b.size()/2,j>=b.size()/2;i++,j--){
		if(b[i] != b [j]){
		    l=0;
		    ans++;
		} 
	}
	if(l){
		cout<<"0";
		return 0;
	}
	cout<<ans;
	return 0;
}
