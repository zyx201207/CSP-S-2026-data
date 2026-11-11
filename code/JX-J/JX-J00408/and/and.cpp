#include<bits/stdc++.h>
using namespace std;
int yu(int x,int y){
	string s1,s2,s3;
	int xx=0;
	while(x){
		s1+=x%2+48;
		x/=2;
	}
	while(y){
		s2+=y%2+48;
		y/=2;
	}
	//cout<<s1<<' '<<s2<<endl;
	int l1=s1.size(),l2=s2.size();
	int l=abs(l1-l2);
	if(l1<l2){
		while(l--) s1+='0';
	}
	else{
		while(l--) s2+='0';
	}
	l=max(l1,l2);
	//cout<<s1<<' '<<s2<<endl;
	int z=1;
	for(int i=0;i<l;i++){
		if(s1[i]=='1'&&s2[i]=='1') xx+=z;
		z*=2;
	}
	return xx;
}
bool cmp(int x,int y){
	return x>y;
}
int a,b,arr[200005],n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>arr[i];
	}
	/*if(b==2){
		for(int i=1;i<a;i++){
			for(int j=i+1;j<=a;j++){
				n=max(n,yu(arr[i],arr[j]));
			}
		}
	}
	else if(b==3){
		for(int i=1;i<a-1;i++){
			for(int j=i+1;j<a;j++){
				for(int ji=j+1;ji<=a;ji++){
					n=max(n,yu(arr[ji],yu(arr[i],arr[j])));
				}
			}
		}
	}*/
	sort(arr+1,arr+a+1,cmp);
	m=arr[1];
	for(int i=2;i<=b;i++){
		m=yu(m,arr[i]);
	}
	cout<<m;
	return 0;
}
