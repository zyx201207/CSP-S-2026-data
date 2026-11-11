#include<bits/stdc++.h>
using namespace std;
#define zhr ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
string a , b , c , d;
pair<int,char> get(string x){
	int idx=0;
	char idxn;
	for(int i=0;i<x.size();i++){
		if(x[i]>='0' && x[i]<='9') {
			idx*=10;
			idx+=(x[i]-'0');
		}
		else idxn=x[i];
	}
	return {idx,idxn};
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	zhr;
	cin>>a>>b>>c>>d;
	if(a!=c) {
		cout<<"0000";
		return 0;
	}
	else{
		
		cout<<"1";
		auto it1 = get(b);
		auto it2 = get(d);
		int idx1 = it1.first;
		int idx2 = it2.first;
		char idxn1 = it1.second;
		char idxn2 = it2.second;
		if(idx1 == idx2) {
			cout<<"1";
		}
		else{
			cout<<"000";
			return 0;
		}
		if((idxn1 >'C' && idxn2 > 'C')||(idxn1 <= 'C' && idxn2 <= 'C')) cout<<"1";
		else {
			cout<<"00";
			return 0;
		}
		if((idxn1=='F' && idxn2=='D') || (idxn1=='D' && idxn2=='F') || (idxn1=='A' && idxn2=='B') || (idxn1=='B' && idxn2=='A') || (idxn1=='B' && idxn2=='C') ||(idxn1=='C' && idxn2=='B')) cout<<"1";
		else cout<<"0";
	}
	
	return 0;
}
