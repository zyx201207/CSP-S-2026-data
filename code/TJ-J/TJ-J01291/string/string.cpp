#include<bits/stdc++.h>
using namespace std;
long long n,m[100002],sum,s,mm,cc;
char ch[100005],k[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i]>>k[i];
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m[i];j++){
			ch[cc]=k[i];
			cc++;
		}
	}
	sum=cc;
	if(sum%2==0){
		s=sum/2;
	}
	else{
		s=(sum+1)/2;
	}
	for(int i=0;i<s;i++){
		if(ch[i]!=ch[sum-1-i]){
			
			mm++;
		}
	}
	cout<<mm;
	return 0;
}
