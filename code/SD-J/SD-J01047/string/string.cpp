#include<bits/stdc++.h>
using namespace std;
int n,num=0;
int a[20001];string b,y;
int app(string a,int l){
	string h;
	if(l%2==0){
		int t=l/2,p=l/2;
		h=a.substr(0,t);
		for(int i=t;i<l;i++)
			if(a[i]!=h[p--])num++;
		}
		else{
			int t=(l-1)/2,p=(l-1)/2;
			h=a.substr(0,t);
			for(int i=t+1;i<l;i++)
			if(a[i]!=h[p--])num++;
		}
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		char t;
		cin>>a[i]>>t;
		for(int j=0;j<a[i];j++)
			b+=t;
		}
		for(int i=b.size()-1;i>=0;i--)y+=b[i];	
	if(b==y){
		fclose(stdin);
		fclose(stdout);
		cout<<0;
		return 0;
	}
	app(b,b.size());
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
