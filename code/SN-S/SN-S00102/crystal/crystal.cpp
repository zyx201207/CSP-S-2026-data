#include<bits/stdc++.h> 
#include<string>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s,sum,pj,k,st;
	s=0;
	sum=0;
	int str[n];
	int str1[n];
	cin>>n>>m;
	k=m;
	st=0;
	for(int i=0;i<n;i++){
		cin>>str[i];
		s=s+str[i];
	}
	pj=s/n;
	for(int i=0;i<n;i++){
		if(pj<str[i]){
			pj++;
		}
		if(pj==str[i]){
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(str[i]<pj){
			str1[i]=pj-str[i];
			pj++;
		}
	}
	for(int i=0;i<n;i++){
		m=m-str1[st-i];
		if(m=0){
			break;
		}
		sum++;
	}
	cout<<sum<<endl;
	return 0;//15.02
}
