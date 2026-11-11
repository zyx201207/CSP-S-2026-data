#include <bits/stdc++.h>
using namespace std;
string hw (int a, char c){
	string s1;
	for(int i=0;i<a;i++){
		s1+=c;
	}
	return s1;
} 
bool hwc(string w){
	bool ihwc=true;
	int num=w.size()-1;
	for(int i=0;i<w.size();i++){
		if(w[i]!=w[num]){
			ihwc=false;
		}
		num--;
	}
	return ihwc;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char q;
	cin>>a;
	string sum;
	for(int i=0;i<a;i++){
		cin>>n>>q;
		sum+=hw(n,q);
	}
	int qwe=0,e=sum.size();
	for(int i=0;i<e/2;i++){
		if(hwc(sum)){
			cout<<0;
			break;
		}
		if(sum[i]!=sum[e]){
			qwe++;
		}
		e--;
	}
	cout<<qwe;
}
