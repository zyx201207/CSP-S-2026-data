//SN-J00781 范任哲 延安市宝塔区高新学校（延安无锡实验学校） 
#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	int a;
	char b;
	cin>>n;
	string s="";
	int x=0;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s[x]=b;
			x++;
		}
	}
	x--;
	for(int i=0;i<x/2;i++){
		if(s[i]!=s[x-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
