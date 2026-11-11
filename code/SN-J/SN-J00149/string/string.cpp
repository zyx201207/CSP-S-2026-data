#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[20005],sum=0,cnt=0;
	char c[20005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
			sum++;
		}
	}
	for(int i=0;i<=sum/2;i++){
		if(int(s[i])!=int(s[sum-1-i])){
			cnt++;
			s[sum-1-i]=s[i];
		}
	}
	cout<<cnt;
	/* 
	long long n,a[20005],sum=0,cnt=0;
	char c[20005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int id1=0,id2=n-1,front,behind;
	while(id1==id2){//´ý¶¨ 
		if(c[id1]!=c[id2]&&front==0&&behind==0){
			sum+=abs(a[id1]-a[id2]);
			if(a[id1]>a[id2]){
				front=a[id1]-a[id2];
			}else{
				behind=a[id2]-a[id1];
			}
		}
		if
		if(c[id1]!=c[id2]&&front>0&&behind==0){
			id2--;
			if(c[id1]==c[id2]){
				
			}
		}
		if(c[id1]!=c[id2]&&behind>0&&front==0){
			id1++;
		}
		
	}
	*/
	return 0;
} 
