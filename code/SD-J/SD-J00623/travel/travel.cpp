#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//我献祭林老师一亿根头发换AC
	//我献祭周扬合一万根头发换AC
	//我献祭GH一米身高换AC
	//CSP为什么不帮考生处理好数据?
	//因为他很CS 
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a.size()!=c.size()){
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<a.size();i++){
		if(a[i]!=c[i]){
			cout<<0<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	if(b.size()!=d.size()){
		cout<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<b.size()-1;i++){
		if(d[i]!=b[i]){
			cout<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	int l=b.size()-1;
	if(b[l]=='A'){
		if(d[l]=='B'){
			cout<<1<<1;
		}else if(d[l]=='C'){
			cout<<1<<0;
		}else{
			cout<<0<<0;
		}
	}
	if(b[l]=='B'){
		if(d[l]=='C'||d[l]=='A'){
			cout<<1<<1;
		}else{
			cout<<0<<0;
		}
	}
	if(b[l]=='C'){
		if(d[l]=='B'){
			cout<<1<<1;
		}else if(d[l]=='A'){
			cout<<1<<0;
		}else{
			cout<<0<<0;
		}
	}
	if(b[l]=='D'){
		if(d[l]=='F'){
			cout<<1<<1;
		}else{
			cout<<0<<0;
		}
	}
	if(b[l]=='F'){
		if(d[l]=='D'){
			cout<<1<<1;
		}else{
			cout<<0<<0;
		}
	}
	return 0;
}
