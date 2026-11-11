#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string q,c;
	long long a;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		while(a--){
			q+=c;
		}
	}
//	cout<<q;
	long long x=0;
	for(int i=0;i<q.size()/2+1;i++){
		if(q[i]!=q[q.size()-i-1]) ++x;
	}
	cout<<x;
	/*
	//cout<<x;
	long long l=0,r=q.size()-1,sum=0;
	while(l<r){
		string u,v;
		u[0]=q[l];
		v[0]=q[r];
		if(u==v&&q[l]!=' '&&q[r]!=' '){
		//	cout<<10101;
			q[l]=' ';
			q[r]=' ';
			l++;
			r=q.size()-1;
			sum++;
		}
		else{
			r--;
			
		}
		if(q[l]==' '||q[r]==' ') l++;
	
	}
	cout<<sum;*/
	return 0;
}
