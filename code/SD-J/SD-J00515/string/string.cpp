#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct node{
	long long n;
	char ch;
};
vector<struct node>v;
map<char,bool>mp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long tmp;
		char ch;
		cin>>tmp>>ch;
		struct node a;
		a.n=tmp;
		a.ch=ch;
	}
	int sum=0;
	for(int i=0;i<v.size();i++){
		if(!mp[v[i]]){
			sum++;
			mp[v[i]]=1;
		} 
	}
	if(sum==1){
		cout<<0;
	}
	return 0;
}
