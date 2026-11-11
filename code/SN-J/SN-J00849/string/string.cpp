//王梓桐 SN-J00849 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
string d=" ",d1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		string c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			d+=c;
		}
	}
	for(int i=int(d.size());i>=1;i--){
		d1+=d[i];
	}
	if(d==d1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=int(d.size());i++){
		if(d[i]!=d[d.size()+1-i]){
			cnt++;
			d[d.size()+1-i]=d[i];
		}
	}
	cout<<cnt;
	return 0;
}
