#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,num=0;
struct node{
	long long a;
	string c;
}k[200001];
string str(int x){
	for(int i=0;i<n;i++){
		if(x>k[i].a){
			x-=k[i].a;
		}else{
			return k[i].c;
		}
	}
	return "Error";
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k[i].a>>k[i].c;
		m+=k[i].a;
	}
	for(long long i=0;i<(m/2);i++){
		if(str(i)!=str(m-i)){
			num++;
		}
	}
	cout<<num;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}